#include "arquivo.h"
#include <stdio.h>
#include <string.h>

void arquivoToLista(FILE *fp, ListaConsulta *destino) {
    char linha[TAM_MAX];
    while(fgets(linha, TAM_MAX, fp) != NULL) {
        if (strlen(linha) <= 1) continue;
        char nome[50];
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(nome, linha);

        if (!fgets(linha, TAM_MAX, fp)) break;
        uint idade, qtd_med;
        sscanf(linha, "%u %u", &idade, &qtd_med);

        NoConsulta *no = criarCelulaConsulta(nome, idade);

        for(uint i=0; i<qtd_med; i++) {
            if (!fgets(linha, TAM_MAX, fp)) break;
            linha[strcspn(linha, "\n")] = '\0';

            char med[50];
            uint qtd;
            sscanf(linha, "%s %u", med, &qtd);

            NoMedicamento *no_med = criarCelulaMedicamento(med, qtd);
            insereCelulaMedicamento(&no->dados, no_med);
        }

        insereCelulaConsulta(destino, no);
    }
}