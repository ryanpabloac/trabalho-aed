#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>
#include <stdlib.h>

typedef  unsigned int uint;

typedef struct descritorConsulta ListaConsulta;
typedef struct noConsulta NoConsulta;
typedef struct descritorMedicamento ListaMedicamento;
typedef struct noMedicamento NoMedicamento;

// === DESCRITORES ===
struct descritorMedicamento { //ListaMedicamento => descritor da lista de medicamentos
    NoMedicamento *cabeca;
    NoMedicamento *cauda;
    uint tamanho;
};

struct descritorConsulta { //ListaConsulta => descritor da lista de consultas
    NoConsulta *cabeca;
    NoConsulta *cauda;
    uint tamanho;
};

// === NOS DAS LISTAS ===
struct noMedicamento { //noMedicamento 
    NoMedicamento *ant;
    char nome_medicamento[50]; //NOME DO MEDICAMENTO
    uint quantidade_medicamento_receitado; //QUANTIDADE DE MEDICAMENTO ESPECIFICADO
    NoMedicamento *prox;
};

struct noConsulta { //noConsulta
    NoConsulta *ant;
    ListaMedicamento dados; //LISTA DE MEDICAMENTOS
    char paciente_consultado[50]; //NOME DO PACIENTE
    uint paciente_idade; //IDADE DO PACIENTE
    NoConsulta *prox;
};

void criarListaConsulta(ListaConsulta *lista_consulta);
void criarListaMedicamento(ListaMedicamento *lista_medicamento);
NoConsulta* criarCelulaConsulta(const char* nome_paciente, uint idade_paciente);
NoMedicamento* criarCelulaMedicamento(const char* nome_medicamento, uint quantidade_medicamento_receitado);

#endif
