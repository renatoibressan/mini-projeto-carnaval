#ifndef CRIATURA_H
#define CRIATURA_H

extern char *tipos[18];

typedef struct Criatura {
    char nome[30];
    char tipo1[15];
    char tipo2[15];
    int nivel, hp, atk, def, speed;
} criatura;

void clearScreen(void);
void pausas(int ms);
void slowPrint(const char *txt, int delay);
void limparBuffer(void);
void inicializarVetor(criatura **c);
void ordenarCriaturas(criatura *c);
int criaturaExiste(const char *nomeCriatura);
int tipoExiste(const char *tipo);
criatura criarCriatura(void);
void exibirCriatura(const criatura *c);
void editarCriatura(criatura *c);
void deletarCriatura(criatura **c);

#endif