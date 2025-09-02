#include "lista.h"

void criarListaConsulta(ListaConsulta *L) {
    L->cabeca = NULL;
    L->cauda = NULL;
    L->tamanho = 0;
}

void insereConsultaNoFinal(ListaConsulta *L, Consulta consulta) {
    NoConsulta *novoNo = (NoConsulta*) malloc(sizeof(NoConsulta));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }
    novoNo->dados = consulta;
    novoNo->prox = NULL;

    if (L->cabeca == NULL) {
        novoNo->ant = NULL;
        L->cabeca = novoNo;
        L->cauda = novoNo;
    } else {
        novoNo->ant = L->cauda;
        L->cauda->prox = novoNo;
        L->cauda = novoNo;
    }
    L->tamanho++;
}

void criarListaMedicamento(ListaMedicamento *L) {
    L->cabeca = NULL;
    L->cauda = NULL;
    L->tamanho = 0;
}

void insereMedicamentoNoFinal(ListaMedicamento *L, Medicamento med) {
    NoMedicamento *novoNo = (NoMedicamento*) malloc(sizeof(NoMedicamento));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }
    novoNo->dados = med;
    novoNo->prox = NULL;

    if (L->cabeca == NULL) {
        novoNo->ant = NULL;
        L->cabeca = novoNo;
        L->cauda = novoNo;
    } else {
        novoNo->ant = L->cauda;
        L->cauda->prox = novoNo;
        L->cauda = novoNo;
    }
    L->tamanho++;
}
