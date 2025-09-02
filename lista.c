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

NoConsulta* criarCelulaConsulta(char* nome_paciente, uint idade_paciente){
    NoConsulta* no_criado = (NoConsulta*) malloc(sizeof(NoConsulta));
    if(no_criado == NULL || nome_paciente == NULL || idade_paciente <= 0){
        printf("ERRO AO CRIAR CELULA DE CONSULTA. INFORMACOES INVALIDAS.\n");
        return NULL;
    }
    strcpy(no_criado->paciente_consultado, nome_paciente);
    no_criado->paciente_idade = idade_paciente;
    no_criado->ant = no_criado->prox = NULL;
    return no_criado;
}
NoMedicamento* criarCelulaMedicamento(char* nome_medicamento, uint quantidade_medicamento_receitado){
    NoMedicamento* medicamento_criado = (NoMedicamento*) malloc(sizeof(NoMedicamento));
    if(medicamento_criado == NULL || nome_medicamento == NULL || quantidade_medicamento_receitado <= 0){
        printf("ERRO AO CRIAR CELULA DE MEDICAMENTO. INFORMACOES INVALIDAS.\n");
        return NULL;
    }
    strcpy(medicamento_criado->nome_medicamento, nome_medicamento);
    medicamento_criado->quantidade_medicamento_receitado = quantidade_medicamento_receitado;
    medicamento_criado->ant = medicamento_criado->prox = NULL;
    return medicamento_criado;
}
