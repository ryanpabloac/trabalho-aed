#include "medicamento.h"

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