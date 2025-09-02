#ifndef CONSULTA_H
#define CONSULTA_H

#include "medicamento.h"

typedef struct descritorConsulta ListaConsulta;
typedef struct noConsulta NoConsulta;

struct descritorConsulta { //ListaConsulta => descritor da lista de consultas
    NoConsulta *cabeca;
    NoConsulta *cauda;
    uint tamanho;
};

struct noConsulta { //noConsulta
    NoConsulta *ant;
    ListaMedicamento dados; //LISTA DE MEDICAMENTOS
    char paciente_consultado[50]; //NOME DO PACIENTE
    uint paciente_idade; //IDADE DO PACIENTE
    NoConsulta *prox;
};

void criarListaConsulta(ListaConsulta *lista_consulta);
NoConsulta* criarCelulaConsulta(const char* nome_paciente, uint idade_paciente);
#endif