#ifndef CRIATURA_H
#define CRIATURA_H

typedef struct Criatura {
    char nome[30];
    char tipo1[15];
    char tipo2[15];
    int nivel, hp, atk, def, speed;
} criatura;

extern char *tipos[18];
extern int idx;

void clearScreen(void);
void pausas(int ms);
void slowPrint(const char *txt, int delay);
void limparBuffer(void);
void upperCase(char *c);
void inicializarVetor(criatura ***c);
int criaturaExiste(const char *nomeCriatura, char *nomes[], int count);
int tipoExiste(const char *tipo);
void criarCriatura(criatura **c, char *nomes[], int *count);
void exibirCriatura(const char *nomeCriatura, const criatura **c);
void editarCriatura(const char *nomeCriatura, criatura **c);
void deletarCriatura(criatura ***c, char *nomes[], int *count);
void liberarCriaturas(criatura **c);

#endif