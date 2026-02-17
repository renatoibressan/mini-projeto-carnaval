#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "criatura.h"
#include "arquivo.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void salvarCriaturas(const char *nomeArquivo, criatura **lista) {
    int cadastros = 0;
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Nao foi possivel salvar o arquivo '%s'.\n", nomeArquivo);
        slowPrint("---------------------------------------------\n", 25);
        return;
    }
    for (int i = 0; i < idx; i++) {
        if (lista[i] != NULL) {
            fprintf(arquivo, "%s: %s/%s Lv.%d %d/%d/%d/%d\n", (*lista[i]).nome, (*lista[i]).tipo1, (*lista[i]).tipo2,
                (*lista[i]).nivel, (*lista[i]).hp, (*lista[i]).atk, (*lista[i]).def, (*lista[i]).speed);
            cadastros++;
        }
    }
    fclose(arquivo);
    printf("%d criaturas foram salvas no arquivo '%s'.\n", cadastros, nomeArquivo);
    slowPrint("---------------------------------------------\n", 25);
}
void carregarCriaturas(const char *nomeArquivo, criatura **lista) {
    int i = 0;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Nao foi possivel salvar o arquivo '%s'.\n", nomeArquivo);
        slowPrint("---------------------------------------------\n", 25);
        return;
    }
    while (i < idx) {
        while (fscanf(arquivo, "%29[^:]: %14[^/]/%14s Lv.%d %d/%d/%d/%d", (*lista[i]).nome, (*lista[i]).tipo1, (*lista[i]).tipo2,
            &((*lista[i]).nivel), &((*lista[i]).hp), &((*lista[i]).atk), &((*lista[i]).def), &((*lista[i]).speed)) == 8) {
                slowPrint("---------------------------------------------\n", 25);
                printf("Nome da criatura: %s\n", (*lista[i]).nome);
                slowPrint("---------------------------------------------\n", 25);
                printf("Tipagens: %s/%s\n", (*lista[i]).tipo1, (*lista[i]).tipo2);
                slowPrint("---------------------------------------------\n", 25);
                printf("Nivel: %d\n", (*lista[i]).nivel);
                slowPrint("---------------------------------------------\n", 25);
                printf("Stats:\nHP: %d\nAtaque: %d\nDefesa: %d\nVelocidade: %d\n",
                    (*lista[i]).hp, (*lista[i]).atk, (*lista[i]).def, (*lista[i]).speed);
                slowPrint("---------------------------------------------\n", 25);
            }
        i++;
    }
    fclose(arquivo);
    printf("Foram carregadas do arquivo %d criaturas.\n", i);
    slowPrint("---------------------------------------------\n", 25);
}