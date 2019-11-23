#ifndef MAQUINA_DE_BUSCA_H
#define MAQUINA_DE_BUSCA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

typedef struct{
  string palavra;
  float freq_em_docs;
  float freq_por_cons;
  float importancia;
}Palavra;

typedef struct{
  float coordenadas;
  float freq_por_docs;
}Coordenadas;

void tiraAcento(string &a);

void lowerCase(int palavras, string *words);

void contaRepeticao(int palavras, string words[], string *temp, int &p_rep);

void eliminaRepeticoes(int palavras, string temp[], Palavra *words_new);

void zeraVetor(int tam, int *v);

void trataPalavra(int n, string *a);

void freq_palavras_consulta(int tam1, int tam2, Palavra *words_new, vector <string> q);

void Ordenacao_notas(float *pontos, int *indices, int tam);

#endif  // MAQUINA_DE_BUSCA_H
