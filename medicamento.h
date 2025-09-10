#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef  unsigned int uint;

typedef struct descritorMedicamento ListaMedicamento;
typedef struct noMedicamento NoMedicamento;

struct descritorMedicamento { //ListaMedicamento => descritor da lista de medicamentos
    NoMedicamento *cabeca;
    NoMedicamento *cauda;
    uint tamanho;
};

struct noMedicamento { //noMedicamento 
    NoMedicamento *ant;
    char nome_medicamento[50]; //NOME DO MEDICAMENTO
    uint quantidade_medicamento_receitado; //QUANTIDADE DE MEDICAMENTO ESPECIFICADO
    NoMedicamento *prox;
};

void criarListaMedicamento(ListaMedicamento *lista_medicamento);
NoMedicamento* criarCelulaMedicamento(const char* nome_medicamento, uint quantidade_medicamento_receitado);
void LiberarListaMedicamento(ListaMedicamento *lista_medicamento);
void LiberarNoMedicamento(ListaMedicamento *lista_medicamento, char medicamento[50]);
void insereCelulaMedicamento(ListaMedicamento *lista, NoMedicamento* novo);
void imprimirListaMedicamento(ListaMedicamento *lista);

#endif