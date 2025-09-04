#include "medicamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void criarListaMedicamento(ListaMedicamento *lista_medicamento) {
    lista_medicamento->cabeca = NULL;
    lista_medicamento->cauda = NULL;
    lista_medicamento->tamanho = 0;
}

NoMedicamento* criarCelulaMedicamento(const char* nome_medicamento, uint quantidade_medicamento_receitado){
    if (nome_medicamento == NULL || quantidade_medicamento_receitado == 0) {
        printf("ERRO: informacoes invalidas.\n");
        return NULL;
    }
    NoMedicamento* medicamento_criado = (NoMedicamento*) malloc(sizeof(NoMedicamento));
    if (medicamento_criado == NULL) {
        perror("malloc");
        return NULL;
    }
    strncpy(medicamento_criado->nome_medicamento, nome_medicamento, sizeof(medicamento_criado->nome_medicamento)-1);
    medicamento_criado->nome_medicamento[sizeof(medicamento_criado->nome_medicamento)-1] = '\0';

    medicamento_criado->quantidade_medicamento_receitado = quantidade_medicamento_receitado;
    medicamento_criado->ant = medicamento_criado->prox = NULL;
    return medicamento_criado;
}

void LiberarListaMedicamento(ListaMedicamento *lista_medicamento) {
    NoMedicamento *temp;

    while(lista_medicamento->cabeca != NULL) {
        temp = lista_medicamento->cabeca;
        lista_medicamento->cabeca = temp->prox;
        free(temp);
    }

    lista_medicamento->cauda = NULL;
    lista_medicamento->tamanho = 0;
}

void LiberarNoMedicamento(ListaMedicamento *lista_medicamento, char medicamento[50]) {
    NoMedicamento *iterador = lista_medicamento->cabeca;
    NoMedicamento *ant = NULL;
    NoMedicamento *prox = NULL;

    while(iterador != NULL) {
        prox = iterador->prox;

        if(strcmp(iterador->nome_medicamento, medicamento) == 0) {

            if(ant == NULL) {
                lista_medicamento->cabeca = prox;
                if(prox != NULL) prox->ant = NULL;
                else lista_medicamento->cauda = NULL;
            }
            else if (prox == NULL) {
                ant->prox = NULL;
                lista_medicamento->cauda = ant;
            }
            else {
                ant->prox = prox;
                prox->ant = ant;
            }

            free(iterador);
            lista_medicamento->tamanho--;
            return;
        }
 
        ant = iterador;
        iterador = prox;
    }

    printf("Medicamento %s não encontrado!", medicamento);
    return;
}

void insereCelulaMedicamento(ListaMedicamento *lista, NoMedicamento* novo) {
    if (!lista || !novo) return;

    if (lista->cabeca == NULL) {
        lista->cabeca = lista->cauda = novo;
    } else {
        novo->prox = lista->cabeca;
        lista->cabeca->ant = novo;
        lista->cabeca = novo;
    }
    lista->tamanho++;
}

void imprimirListaMedicamento(ListaMedicamento *lista) {
    if (!lista || lista->cabeca == NULL) {
        printf("Nenhum medicamento cadastrado.\n");
        return;
    }
    NoMedicamento *temp = lista->cabeca;
    while (temp != NULL) {
        printf("Medicamento: %s | Quantidade: %u\n",
               temp->nome_medicamento,
               temp->quantidade_medicamento_receitado);
        temp = temp->prox;
    }
}
