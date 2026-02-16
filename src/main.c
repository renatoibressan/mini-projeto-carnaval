#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criatura.h"
#include "arquivo.h"
#include "menu.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void menuPrincipal(char ch, criatura **c, char *nomes[], int count) {
    clearScreen();
    slowPrint("===== SISTEMA DE CATALOGO DE CRIATURAS =====\n", 60);
    slowPrint("Desenvolvido por:\nRenato Ikeda Bressan\n    ", 40);
    ch = 'x';
    count = 0;
    int aux, checkup = 0;
    char nomeTeste[30];
    clearScreen();
    inicializarVetor(&c);
    while (ch != '0') {
        slowPrint("===== MENU =====\nOpcoes:\n", 50);
        slowPrint("A. Criar uma criatura\n", 25);
        slowPrint("B. Exibir uma criatura\n", 25);
        slowPrint("C. Editar uma criatura\n", 25);
        slowPrint("D. Deletar as criaturas\n", 25);
        slowPrint("E. Salvar as criaturas\n", 25);
        slowPrint("F. Carregar as criaturas\n", 25);
        slowPrint("0. Encerrar o programa\n", 25);
        slowPrint("Escolha uma das opcoes acima: ", 50);
        ch = getchar();
        while ((aux = getchar()) != '\n' && aux != EOF) {}
        clearScreen();
        switch (ch) {
            case 'A':
            case 'a':
                if (checkup == 0) inicializarVetor(&c);
                criarCriatura(c, nomes, &count);
                checkup = 1;
                break;
            case 'B':
            case 'b':
                if (*c == NULL) {
                    slowPrint("Nao ha criaturas para exibir!\n", 50);
                    slowPrint("---------------------------------------------\n", 25);
                    break;
                } else {
                    printf("Insira um nome para procura de criatura: ");
                    scanf("%[^\n]%*c", nomeTeste);
                    exibirCriatura(nomeTeste, c);
                }
                break;
            case 'C':
            case 'c':
                if (*c == NULL) {
                    slowPrint("Nao ha criaturas para editar!\n", 50);
                    slowPrint("---------------------------------------------\n", 25);
                    break;
                } else {
                    printf("Insira um nome para procura de criatura: ");
                    scanf("%[^\n]%*c", nomeTeste);
                    editarCriatura(nomeTeste, c);
                }
                break;
            case 'D':
            case 'd':
                deletarCriatura(&c, nomes, &count);
                checkup = 0;
                break;
            case '0':
                slowPrint("Encerrando o programa...\n", 75);
                break;
            default: printf("Opcao invalida! Pressione ENTER para voltar:\n"); getchar();
        }
    }
    liberarCriaturas(c);
    clearScreen();
}

int main(int argc, char *argv[]) {
    criatura **c;
    char option;
    char *nomes[150];
    int count;
    const char *nomeArquivo = "criaturas.txt";
    if (argc > 1) nomeArquivo = argv[1];
    menuPrincipal(option, c, nomes, count);
    return 0;
}