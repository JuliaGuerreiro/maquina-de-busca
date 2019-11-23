#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <math.h>

#include "maquina_de_busca.h"

using namespace std;

int main(int argc, char *argv[]){

  int n_docs;
  n_docs = argc - 1;
  int palavras = 0;
  int pala = 0;
  int palavras_por_documento[n_docs];

  zeraVetor(n_docs, palavras_por_documento);

  for(int i = 1; i <= n_docs; i++){
  ifstream in(argv[i]);
  string conta;

  if(in.is_open()) {
    while(!in.eof()) {
      in >> conta;
      if(conta.length() >= 1) {
        palavras++;
        palavras_por_documento[i-1]++;
      }
    }
  } else {
    cout << "Arquivo invalido" << endl;
  }

  }

  string words[palavras];
  int d[palavras]; //armazena em qual documento a palavra i está

  for(int i = 1; i <= n_docs; i++){
  ifstream in(argv[i]);

   int n = palavras_por_documento[i-1];
   pala = n + pala;

   string a[n];
  for(int i = 0; i < n; i++){
    in >> a[i];
  }

 trataPalavra(n, a);

 int s = 0;
  for(int l = pala - n; l < pala; l++){
    words[l] = a[s];
    d[l] = i;
    s++;
  }
}

  lowerCase(palavras, words);

 for(int i = 0; i < palavras; i++){
    tiraAcento(words[i]);
 }

  int p_rep = 0;
  string temp[palavras];
  for(int i = 0; i < palavras; i++){
    temp[i] = words[i];
  }

  contaRepeticao(palavras, words, temp, p_rep);

  int pal = palavras - p_rep;

  Palavra words_new[pal];
  Coordenadas palavras_por_docs[pal][n_docs];

  eliminaRepeticoes(palavras, temp, words_new);

  list <int> docs[pal]; // lista em quais documentos tal palavra aparece

  for(int i = 0; i < pal; i++){
    for(int j = 0; j < n_docs; j++){
        palavras_por_docs[i][j].freq_por_docs = 0;
        words_new[i].freq_por_cons = 0;
    }
  }

  for(int i = 0; i < pal; i++){
    for(int j = 0; j < palavras; j++){
      if(words_new[i].palavra == words[j]){
        docs[i].push_back(d[j]);
        palavras_por_docs[i][d[j]-1].freq_por_docs++;
      }
    }
  }

  for(int i = 0; i < pal; i++){
    words_new[i].freq_em_docs = docs[i].size();
  }

  for(int i = 0; i < pal; i++){
    for(int j = 0; j < n_docs; j++){
      palavras_por_docs[i][j].coordenadas = palavras_por_docs[i][j].freq_por_docs*(log(n_docs/float(words_new[i].freq_em_docs))/float(log(2)));
    }
  }

  cout << "Digite sua busca:" << endl;
  string consulta;

  getline(cin, consulta);
  ofstream cono("q.txt");

  cono << consulta;
  cono.close();

  string aux;
  vector <string> q;

  ifstream conin("q.txt");
  while(!conin.eof()) {
      conin >> aux;
      if(aux.length() >= 1) {
        q.push_back(aux);
        }
    }

  freq_palavras_consulta(pal, q.size(), words_new, q);

  Coordenadas palavras_por_consulta[pal];

  for(int i = 0; i < pal; i++){
    palavras_por_consulta[i].coordenadas = words_new[i].freq_por_cons*(log(n_docs/float(words_new[i].freq_em_docs))/float(log(2)));
  }

  float coor_ao_quad_docs[pal][n_docs], coor_ao_quad_cons[pal];
  float stemp[pal][n_docs], stemp2[pal], stemp3 = 0;
  float similaridade[n_docs];

  for(int i = 0; i < pal; i++){
        coor_ao_quad_cons[i] = palavras_por_consulta[i].coordenadas*palavras_por_consulta[i].coordenadas;
        stemp2[i] = 0;
    for(int j = 0; j < n_docs; j++){
        coor_ao_quad_docs[i][j] = palavras_por_docs[i][j].coordenadas*palavras_por_docs[i][j].coordenadas;
    }
  }

  for(int i = 0; i < n_docs; i++){
    for(int j = 0; j < pal; j++){
        stemp2[i] = stemp2[i] + coor_ao_quad_docs[j][i];
        stemp3 = stemp3 + coor_ao_quad_cons[i];
    }
  }

  for(int i = 0; i < pal; i++){
    for(int j = 0; j < n_docs; j++){
        stemp[i][j] = palavras_por_docs[i][j].coordenadas*palavras_por_consulta[i].coordenadas;
        similaridade[j] = 0;
        }
  }

  for(int i = 0; i < n_docs; i++){
    for(int j = 0; j < pal; j++){
        similaridade[i] = similaridade[i] + stemp[j][i];
    }
  }

   float sim_final[n_docs];
   int indices[n_docs];
   for(int i = 0; i < n_docs; i++){
    sim_final[i] = similaridade[i]/(sqrt(stemp2[i])*sqrt(stemp3));
    indices[i] = i;
   }

   cout << endl;

   Ordenacao_notas(sim_final, indices, n_docs);
   cout << "Ranking" << endl;

   for(int i = 0; i < n_docs; i++){
    cout << i+1 << ":" << "D" << indices[i]+1 << endl;
   }

  return 0;
}
