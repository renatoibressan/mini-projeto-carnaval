#ifndef CRIATURA_H
#define CRIATURA_H

typedef struct Criatura {
    char nome[30];
    char tipo[15];
    int nivel, hp, atk, def;
} criatura;

void clearScreen(void);
void pausas(int ms);
void slowPrint(const char *txt, int delay);
void limparBuffer(void);
void ordenarCriaturas(criatura *c);
int criaturaExiste(const char *nome);
criatura criarCriatura(void);
void exibirCriatura(const criatura *c);
void editarCriatura(criatura *c);
void deletarCriatura(criatura **c);

#endif