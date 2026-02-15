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

void menuPrincipal(void) {
    clearScreen();
    slowPrint("===== SISTEMA GERENCIADOR DE BAIRROS =====\n", 60);
    slowPrint("Desenvolvido por:\nRenato Ikeda Bressan\n    ", 40);
    clearScreen();
}

int main(int argc, char *argv[]) {
    criatura *c;
    menuPrincipal();
    return 0;
}