#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "consulta.h"

void criarListaConsulta(ListaConsulta *lista_consulta) {
    lista_consulta->cabeca = NULL;
    lista_consulta->cauda = NULL;
    lista_consulta->tamanho = 0;
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
void insereCelulaConsulta(ListaConsulta *lista_consulta, NoConsulta* dados){
    if(lista_consulta == NULL){
        printf("lista invalida.\n");
        return;
    }
    if(dados == NULL || strlen(dados->paciente_consultado) == 0 || dados->paciente_idade == 0){
        printf("dados errados.\n");
        return;
    }
    if(lista_consulta->cabeca == NULL){
        lista_consulta->cabeca = lista_consulta->cauda = dados;
    }else{
        dados->prox = lista_consulta->cabeca;
        dados->ant = NULL;
        lista_consulta->cabeca->ant = dados;
        lista_consulta->cabeca = dados;
    }
    lista_consulta->tamanho++;
}
void imprimirListaConsulta(ListaConsulta *lista_consulta){
    if(lista_consulta == NULL){
        printf("Lista invalida.\n");
        return;
    }
    if (lista_consulta->cabeca == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    NoConsulta* temporario = lista_consulta->cabeca;
    while(temporario != NULL){
        printf("=== CONSULTA ===\n");
        printf("NOME PACIENTE: %s\n", temporario->paciente_consultado);
        printf("IDADE PACIENTE: %d\n", temporario->paciente_idade);
        temporario = temporario->prox;
    }
}
void buscarPacienteConsulta(ListaConsulta *lista_consulta, const char* nome_paciente){
    if (lista_consulta == NULL) {
        printf("Lista invalida.\n");
        return;
    }
    if (lista_consulta->cabeca == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    if (nome_paciente == NULL) {
        printf("Nome de paciente invalido.\n");
        return;
    }

    NoConsulta* temporario = lista_consulta->cabeca;
    while (temporario != NULL) {
        if (strcasecmp(temporario->paciente_consultado, nome_paciente) == 0) {
            printf("=== DADOS DO PACIENTE ===\n");
            printf("NOME PACIENTE: %s\n", temporario->paciente_consultado);
            printf("IDADE PACIENTE: %u\n", temporario->paciente_idade);
            return;
        }
        temporario = temporario->prox;
    }

    printf("=== PACIENTE NAO ENCONTRADO ===\n");
}
void removerPacienteConsulta(ListaConsulta *lista_consulta, const char* nome_paciente){
    if (!lista_consulta) {
        printf("Lista invalida.\n");
        return;
    }
    if (!lista_consulta->cabeca) {
        printf("Lista vazia.\n");
        return;
    }
    if (!nome_paciente) {
        printf("Nome de paciente invalido.\n");
        return;
    }

    NoConsulta* temporario = lista_consulta->cabeca;
    while (temporario) {
        if (strcasecmp(temporario->paciente_consultado, nome_paciente) == 0) {
            // Atualiza ponteiros da lista
            if (temporario->ant)
                temporario->ant->prox = temporario->prox;
            else
                lista_consulta->cabeca = temporario->prox; // removendo o primeiro

            if (temporario->prox)
                temporario->prox->ant = temporario->ant;
            else
                lista_consulta->cauda = temporario->ant; // removendo o último

            free(temporario);
            lista_consulta->tamanho--;
            printf("Paciente removido com sucesso.\n");
            return;
        }
        temporario = temporario->prox;
    }

    printf("Paciente nao encontrado.\n");
}
