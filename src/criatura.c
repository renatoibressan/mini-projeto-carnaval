#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criatura.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

char *tipos[18] = {"Grama", "Fogo", "Agua", "Normal", "Eletrico", "Psiquico",
                "Lutador", "Pedra", "Terrestre", "Voador", "Inseto", "Veneno",
                "Sombrio", "Fantasma", "Gelo", "Aco", "Dragao", "Fada"};
int idx = 0;
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
void upperCase(char *c) {
    if (*c >= 'a' && *c <= 'z') *c -= 32;
}
void inicializarVetor(criatura ***c) {
    *c = malloc(150*sizeof(criatura*));
    for (int i = 0; i < 150; i++) {
        (*c)[i] = NULL;
    }
}
int criaturaExiste(const char *nomeCriatura, char *nomes[], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(nomeCriatura, nomes[i]) == 0) return 1;
    }
    return 0;
}
int tipoExiste(const char *tipo) {
    for (int i = 0; i < 18; i++) {
        if (strcmp(tipo, tipos[i]) == 0) return 1;
    }
    return 0;
}
void criarCriatura(criatura **c, char *nomes[], int *count) {
    char novoNome[30];
    char novoTipo1[15];
    char novoTipo2[15];
    criatura *crit = malloc(sizeof(criatura));
    printf("Por favor, insira os dados:\n");
    do {
        printf("Nome da criatura: ");
        scanf(" %[^\n]%*c", novoNome);
        upperCase(&novoNome[0]);
        if (criaturaExiste(novoNome, nomes, *count)) {
            slowPrint("---------------------------------------------\n", 25);
            printf("O nome '%s' ja esta em uso. Por favor, digite outro nome:\n", novoNome);
            slowPrint("---------------------------------------------\n", 25);
        } else {
            strcpy((*crit).nome, novoNome);
            break;
        }
    } while (1);
    do {
        printf("Tipo primario da criatura: ");
        scanf("%s", novoTipo1);
        limparBuffer();
        upperCase(&novoTipo1[0]);
        if (!tipoExiste(novoTipo1)) {
            slowPrint("---------------------------------------------\n", 25);
            printf("Por favor, use um tipo valido.\n");
            slowPrint("---------------------------------------------\n", 25);
        } else {
            strcpy((*crit).tipo1, novoTipo1);
            break;
        }
    } while (1);
    printf("Tipo secundario da criatura: ");
    scanf("%s", novoTipo2);
    limparBuffer();
    upperCase(&novoTipo2[0]);
    if (!tipoExiste(novoTipo2)) strcpy((*crit).tipo2, "---");
    else strcpy((*crit).tipo2, novoTipo2);
    printf("Nivel da criatura: ");
    scanf("%d", &((*crit).nivel));
    limparBuffer();
    printf("Stats da criatura:\nHP: ");
    scanf("%d", &((*crit).hp));
    limparBuffer();
    printf("Ataque: ");
    scanf("%d", &((*crit).atk));
    limparBuffer();
    printf("Defesa: ");
    scanf("%d", &((*crit).def));
    limparBuffer();
    printf("Velocidade: ");
    scanf("%d", &((*crit).speed));
    c[idx] = crit;
    strcpy(nomes[*count], (*crit).nome);
    (*count)++;
    slowPrint("---------------------------------------------\n", 25);
    printf("Criatura '%s' catalogada com sucesso!\n", (*c[idx]).nome);
    slowPrint("---------------------------------------------\n", 25);
    idx++;
}
void exibirCriatura(const char *nomeCriatura, criatura **c) {
    int i = 0;
    int found = 0;
    while (i < idx) {
        if (strcmp(nomeCriatura, (*c[i]).nome) == 0) {
            slowPrint("---------------------------------------------\n", 25);
            printf("Criatura '%s' encontrada!\n", (*c[i]).nome);
            slowPrint("---------------------------------------------\n", 25);
            printf("Tipagens: %s/%s\n", (*c[i]).tipo1, (*c[i]).tipo2);
            slowPrint("---------------------------------------------\n", 25);
            printf("Nivel: %d\n", (*c[i]).nivel);
            printf("Stats:\nHP: %d\nAtaque: %d\nDefesa: %d\nVelocidade: %d\n", (*c[i]).hp, (*c[i]).atk, (*c[i]).def, (*c[i]).speed);
            slowPrint("---------------------------------------------\n", 25);
            found = 1;
            break;
        }
        i++;
    }
    if (!found) {
        printf("Nenhuma criatura de nome '%s' foi encontrada.\n", nomeCriatura);
        slowPrint("---------------------------------------------\n", 25);
        return;
    }
}
void editarCriatura(const char *nomeCriatura, criatura **c) {
    int option, found = 0;
    criatura *crit = malloc(sizeof(crit));
    for (int i = 0; i < idx; i++) {
        if (strcmp(nomeCriatura, (*c[i]).nome) == 0) {
            slowPrint("Opcoes:\n", 25);
            slowPrint("1. Editar tipo primario da criatura\n", 25);
            slowPrint("2. Editar tipo secundario da criatura\n", 25);
            slowPrint("3. Editar nivel da criatura\n", 25);
            slowPrint("4. Editar HP da criatura\n", 25);
            slowPrint("5. Editar ataque da criatura\n", 25);
            slowPrint("6. Editar defesa da criatura\n", 25);
            slowPrint("7. Editar velocidade da criatura\n", 25);
            slowPrint("Qual edicao deseja realizar? ", 25);
            scanf("%d", &option);
            limparBuffer();
            switch (option) {
                case 1:
                    do {
                        printf("Insira o novo tipo primario da criatura: ");
                        scanf("%[^\n]%*c", (*crit).tipo1);
                        if (!tipoExiste((*crit).tipo1)) {
                            slowPrint("---------------------------------------------\n", 25);
                            printf("Por favor, use um tipo valido.\n");
                            slowPrint("---------------------------------------------\n", 25);
                        } else {
                            strcpy((*c[i]).tipo1, (*crit).tipo1);
                        }
                    } while (1);
                    break;
                case 2:
                    printf("Insira o novo tipo secundario da criatura: ");
                    scanf("%[^\n]%*c", (*crit).tipo2);
                    if (!tipoExiste((*crit).tipo2)) strcpy((*c[i]).tipo2, "---");
                    else strcpy((*c[i]).tipo2, (*crit).tipo2);
                    break;
                case 3:
                    printf("Insira o novo nivel da criatura: ");
                    scanf("%d", &((*crit).nivel));
                    limparBuffer();
                    (*c[i]).nivel = (*crit).nivel;
                    break;
                case 4:
                    printf("Insira o novo HP da criatura: ");
                    scanf("%d", &((*crit).hp));
                    limparBuffer();
                    (*c[i]).hp = (*crit).hp;
                    break;
                case 5:
                    printf("Insira o novo ataque da criatura: ");
                    scanf("%d", &((*crit).atk));
                    limparBuffer();
                    (*c[i]).atk = (*crit).atk;
                    break;
                case 6:
                    printf("Insira a nova defesa da criatura: ");
                    scanf("%d", &((*crit).def));
                    limparBuffer();
                    (*c[i]).def = (*crit).def;
                    break;
                case 7:
                    printf("Insira a nova velocidade da criatura: ");
                    scanf("%d", &((*crit).speed));
                    limparBuffer();
                    (*c[i]).speed = (*crit).speed;
                    break;
                default:
                    printf("Opcao invalida!\n");
                    scanf("%d", &option);
                    limparBuffer();
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Nenhuma criatura de nome '%s' foi encontrada.\n", nomeCriatura);
        slowPrint("---------------------------------------------\n", 25);
        return;
    }
}
void deletarCriatura(criatura ***c, char *nomes[], int *count) {
    int i;
    for (i = 0; i < 150; i++) {
        if ((*c)[i] != NULL) {
            printf("Criatura '%s' deletada com sucesso!\n", (*(*c)[i]).nome);
            free((*c)[i]);
            (*c)[i] = NULL;
        }
    }
    *count = 0;
    for (i = 0; i < 150; i++) {
        memset(nomes[i], 0, sizeof(nomes[i]));
    }
    idx = 0;
    printf("Criaturas deletadas com sucesso!\n");
    slowPrint("---------------------------------------------\n", 25);
}
void liberarCriaturas(criatura **c) {
    if (c == NULL) return;
    for (int i = 0; i < idx; i++) {
        if (c[i] != NULL) {
            free(c[i]);
            c[i] = NULL;
        }
    }
    free(c);
    idx = 0;
}