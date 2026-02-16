#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "criatura.h"

void salvarCriaturas(const char *nomeArquivo, criatura **lista);
void carregarCriaturas(const char *nomeArquivo, criatura **lista);

#endif