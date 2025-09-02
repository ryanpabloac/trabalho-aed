#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criarListaConsulta(ListaConsulta *lista_consulta) {
    lista_consulta->cabeca = NULL;
    lista_consulta->cauda = NULL;
    lista_consulta->tamanho = 0;
}

void criarListaMedicamento(ListaMedicamento *lista_medicamento) {
    lista_medicamento->cabeca = NULL;
    lista_medicamento->cauda = NULL;
    lista_medicamento->tamanho = 0;
}

NoConsulta* criarCelulaConsulta(const char* nome_paciente, uint idade_paciente){
    if (nome_paciente == NULL || idade_paciente == 0) {
        printf("ERRO: informacoes invalidas.\n");
        return NULL;
    }
    NoConsulta* no_criado = (NoConsulta*) malloc(sizeof(NoConsulta));
    if (no_criado == NULL) {
        perror("malloc");
        return NULL;
    }
    strncpy(no_criado->paciente_consultado, nome_paciente, sizeof(no_criado->paciente_consultado)-1);
    no_criado->paciente_consultado[sizeof(no_criado->paciente_consultado)-1] = '\0';

    no_criado->paciente_idade = idade_paciente;
    no_criado->ant = no_criado->prox = NULL;

    criarListaMedicamento(&no_criado->dados); // inicializa a lista interna de medicamentos

    return no_criado;
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
