#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criatura.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>

char *tipos[18] = {"Grama", "Fogo", "Agua", "Normal", "Eletrico", "Psiquico", "Lutador", "Pedra", "Terrestre",
                "Voador", "Inseto", "Veneno", "Sombrio", "Fantasma", "Gelo", "Aco", "Dragao", "Fada"};

#endif