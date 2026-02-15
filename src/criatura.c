#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criatura.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

char *tipos[18] = {"Grama", "Fogo", "Agua", "Normal", "Eletrico", "Psiquico", "Lutador", "Pedra", "Terrestre",
                "Voador", "Inseto", "Veneno", "Sombrio", "Fantasma", "Gelo", "Aco", "Dragao", "Fada"};
void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void pausas(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}
void slowPrint(const char *txt, int delay) {
    for (int i = 0; i < strlen(txt); i++) {
        putchar(txt[i]);
        fflush(stdout);
        pausas(delay);
    }
}
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}