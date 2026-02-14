#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "criatura.h"

void clearScreen(void);
void pausas(int ms);
void slowPrint(const char *txt, int delay);
void limparBuffer(void);
void ordenarCriaturas(criatura *c);
void salvarCriaturas(const char *nomeArquivo, criatura *lista, int qtd);
void carregarCriaturas(const char *nomeArquivo, criatura **lista);

#endif