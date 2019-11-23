#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <math.h>

#include "maquina_de_busca.h"

using namespace std;

void tiraAcento(string &a){
  char b[23] = {'+','-','.',';','!','@','#','$','%','&','*','(',')','{','}','|', '/', ':', '<', '>', '"','?', ','};

  std::string::iterator it;
  int x = 0;
  vector <int> v;
  for(it=a.begin(); it!=a.end(); it++){
    for(int i = 0; i < 23; i++){
    if(*it == b[i]){
      v.push_back(x);
    }
    }
    x++;
  }

 for(int i = 0; i < v.size(); i++){
   v[i] = v[i] - i;
 }

 for(int i = 0; i < v.size(); i++){
  a.erase(a.begin()+v[i]);
 }
}

void lowerCase(int palavras, string *words){
 std::string::iterator it;

 for(int i = 0; i < palavras; i++){
  for(it=words[i].begin(); it!=words[i].end(); it++){
   *it = tolower(*it);
  }
 }
}

void contaRepeticao(int palavras, string words[], string *temp, int &p_rep){
  for(int i = 0; i < palavras; i++){
    for(int j = i+1; j < palavras; j++){
      if(words[i] == words[j]){
        temp[j] = "0";
      }
    }
  }

  for(int i = 0; i < palavras; i++){
    if(temp[i] == "0"){
        p_rep++;
    }
  }
}

void eliminaRepeticoes(int palavras, string temp[], Palavra *words_new){
  int k = 0;
  for(int i = 0; i < palavras; i++){
    if(temp[i] != "0"){
        words_new[k].palavra = temp[i];
        k++;
    }
  }
}

void zeraVetor(int tam, int *v){
   for(int i = 0; i < tam; i++){
     v[i] = 0;
  }
}

void trataPalavra(int n, string *a){
   string v[n], y[n], e[n];
   for(int i = 0; i < n; i++){
   v[i] = a[i];
   y[i] = a[i];
   e[i] = a[i];
 }

for(int i = 0; i < n; i++){
   v[i].pop_back();
   v[i].push_back('.');
   y[i].pop_back();
   y[i].push_back('?');
   e[i].pop_back();
   e[i].push_back('!');

   if(v[i] == a[i]){
     a[i].pop_back();
   }else if(y[i] == a[i]){
     a[i].pop_back();
   }else if(e[i] == a[i]){
     a[i].pop_back();
   }
 }
}

void freq_palavras_consulta(int tam1, int tam2, Palavra *words_new, vector <string> q){
  for(int i = 0; i < tam1; i++){
    for(int j = 0; j < tam2; j++){
        if(words_new[i].palavra == q[j]){
            words_new[i].freq_por_cons++;
        }
    }
  }
}

void Ordenacao_notas(float *pontos, int *indices, int tam){
    float aux, aux2;

       for(int i = 0; i < tam; i++){
         for(int j = i + 1; j < tam; j++){
            if(pontos[i] < pontos[j]){
                aux = pontos[j];
                pontos[j] = pontos[i];
                pontos[i] = aux;

                aux2 = indices[j];
                indices[j] = indices[i];
                indices[i] = aux2;
            }
         }
       }
}

