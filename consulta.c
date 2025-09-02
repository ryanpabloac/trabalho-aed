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