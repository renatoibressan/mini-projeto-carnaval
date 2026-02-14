#ifndef CRIATURA_H
#define CRIATURA_H

char *tipos[18] = {"Grama", "Fogo", "Agua", "Normal", "Eletrico", "Psiquico", "Lutador", "Pedra", "Terrestre",
                "Voador", "Inseto", "Veneno", "Sombrio", "Fantasma", "Gelo", "Aco", "Dragao", "Fada"};

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
void ordenarCriaturas(criatura *c);
int criaturaExiste(const char *nomeCriatura);
int tipoExiste(const char *tipo);
criatura criarCriatura(void);
void exibirCriatura(const criatura *c);
void editarCriatura(criatura *c);
void deletarCriatura(criatura **c);

#endif