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
    printf("Hello, World!\n");
}

int main(void) {
    criatura *c;
    menuPrincipal();
    return 0;
}