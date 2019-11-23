#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "maquina_de_busca.h"

#include "doctest.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST_CASE("TiraAcentos") {
    string a = "guarda-chuvas";
    string b = "oi.oi";
    string c = "dia-a-dia?";

    tiraAcento(a);
    tiraAcento(b);
    tiraAcento(c);

    CHECK(a == "guardachuvas");
    CHECK(b == "oioi");
    CHECK(c == "diaadia");
}

TEST_CASE("lowerCase") {
    string a = "OI";
    string b = "Oi";
    string c = "OiMuNdO";

    lowerCase(1, &a);
    lowerCase(1, &b);
    lowerCase(1, &c);

    CHECK(a == "oi");
    CHECK(b == "oi");
    CHECK(c == "oimundo");
}

TEST_CASE("ContaRepeticoes") {
    string a[5], b[5];
    int c = 0;
    a[0] = "oi";
    a[1] = "oi";
    a[2] = "tudo";
    a[3] = "bem";
    a[4] = "bem";

    for(int i = 0; i < 5; i++){
    b[i] = a[i];
    }

    contaRepeticao(5, a, b, c);

    CHECK(c == 2);
}

TEST_CASE("Zerar") {
  int v[5];
  zeraVetor(5, v);

  CHECK(v[0] == 0);
  CHECK(v[1] == 0);
  CHECK(v[2] == 0);
  CHECK(v[3] == 0);
  CHECK(v[4] == 0);
}

TEST_CASE("Ordenacao") {
  float v[5];
  int ind[5] = {0,1,2,3,4};

  v[0] = 2;
  v[1] = 1;
  v[2] = 3.5;
  v[3] = 4;
  v[4] = 5;

  Ordenacao_notas(v, ind, 5);

  CHECK(v[0] == 5);
  CHECK(v[1] == 4);
  CHECK(v[2] == 3.5);
  CHECK(v[3] == 2);
  CHECK(v[4] == 1);
}

TEST_CASE("TrataFuncao") {
  string a = "oi.";
  string b = "voce?";

  trataPalavra(1, &a);
  trataPalavra(1, &b);

  CHECK(a == "oi");
  CHECK(b == "voce");
}
