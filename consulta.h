#ifndef CONSULTA_H
#define CONSULTA_H

#include "medicamento.h"

typedef  unsigned int uint;
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
void imprimirListaConsulta(ListaConsulta *lista_consulta);
void insereCelulaConsulta(ListaConsulta *lista_consulta, NoConsulta* dados);
void buscarPacienteConsulta(ListaConsulta *lista_consulta, const char* nome_paciente);
void removerPacienteConsulta(ListaConsulta *lista_consulta, const char* nome_paciente);
void LiberarListaConsulta(ListaConsulta *lista_consulta);
void adicionarMedicamentoPaciente(NoConsulta *paciente, const char* nome, uint quantidade);
void removerMedicamentoPaciente(NoConsulta *paciente, const char* nome);
void imprimirMedicamentosPaciente(NoConsulta *paciente);
void gerarRelatorio(ListaConsulta *lista);
void percorrePacientes(ListaConsulta *lista);

#endif