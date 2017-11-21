#define PRETO 0
#define VERMELHO 1

typedef struct nodo{
  int chave;
  int cor;
  struct nodo* dir;
  struct nodo* esq;
  struct nodo* pai;
}TpNodo;
  
TpNodo* insere(TpNodo* root, int chave, TpNodo* pai);
TpNodo* fixup(TpNodo* PV, int chave);
void print(TpNodo* PV,int i);
void menu();
void ffree(TpNodo* PV);
