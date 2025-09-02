#ifndef LISTA_H
#define LISTA_H

typedef  unsigned int uint;

typedef struct descritorConsulta ListaConsulta;
typedef struct noConsulta NoConsulta;
typedef struct descritorMedicamento ListaMedicamento;
typedef struct noMedicamento NoMedicamento;

struct descritorConsulta {
    NoConsulta *cabeca;
    NoConsulta *cauda;
    uint tamanho;
};

struct noConsulta {
    NoConsulta *ant;
    ListaMedicamento dados;
    NoConsulta *prox;
};

struct descritorMedicamento {
    NoMedicamento *cabeca;
    NoMedicamento *cauda;
    uint tamanho;
};

struct noMedicamento {
    NoMedicamento *ant;
    ListaMedicamento dados;
    NoMedicamento *prox;
};

void criarListaConsulta(ListaConsulta *);
void criarListaMedicamento(ListaMedicamento *);
#endif