#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "medicamento.h"
#include "consulta.h"

typedef  unsigned int uint;

#define TAM_MAX 50

void arquivoToLista(FILE *fp, ListaConsulta *destino);
#endif