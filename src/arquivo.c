#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criatura.h"
#include "arquivo.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void salvarCriaturas(const char *nomeArquivo, criatura **lista, int qtd) {
}
void carregarCriaturas(const char *nomeArquivo, criatura ***lista) {
}