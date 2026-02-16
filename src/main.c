#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "criatura.h"
#include "arquivo.h"
#include "menu.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(int argc, char *argv[]) {
    criatura **c;
    char option;
    char *nomes[150];
    int count;
    const char *nomeArquivo = "criaturas.txt";
    if (argc > 1) nomeArquivo = argv[1];
    menuPrincipal(option, c, nomes, count, nomeArquivo);
    return 0;
}