#include "RN.h"

TpNodo* insere(TpNodo* root, int chave, TpNodo* pai){  
  if(root == NULL){
    TpNodo* aux = (TpNodo*)malloc(sizeof(TpNodo));
    aux->chave = chave; 
    aux->cor = VERMELHO; 
    aux->dir = NULL;
    aux->esq = NULL; 
    aux->pai = pai; 
    return aux;
  }
  if(chave < root->chave) root->esq = insere(root->esq, chave, root);
  if(chave > root->chave) root->dir = insere(root->dir, chave, root);
  if(root->chave == chave) printf("Este elemento ja foi inserido!!");
  return root;    
}

TpNodo* fixup(TpNodo* PV, int chave){
  TpNodo* fix = PV;
  while(fix->chave != chave){
    if(fix->chave > chave) fix = fix->esq;
    else fix = fix->dir;
  } // FIX tem o nodo inserido
  if(fix == PV) return PV;
  if(fix->pai != NULL && (fix->pai)->cor == PRETO) return PV;  
  TpNodo* avo = (fix->pai)->pai;
  TpNodo* tio;
  if(avo->chave > chave) tio = avo->dir;
  else tio = avo->esq;
  if(tio != NULL && tio->cor == VERMELHO){ // CASO1
    do{
      tio->cor = PRETO;
      (fix->pai)->cor = PRETO;
      avo->cor = VERMELHO;
      if(avo->pai != NULL && (avo->pai)->cor == VERMELHO){
	fix = avo;
	chave = fix->chave;
	avo = (avo->pai)->pai;
	if(avo->chave > chave) tio = avo->dir;
	else tio = avo->esq;
      }
      else return PV;
    }while(tio != NULL && tio->cor == VERMELHO);
  }
  if(((fix->pai)->chave < chave && (fix->pai)->chave < avo->chave) ||
     ((fix->pai)->chave > chave && (fix->pai)->chave > avo->chave)){// CASO2
    TpNodo* novo = fix->pai;
    fix->pai = novo->pai;
    novo->pai = fix;
    if(avo->chave > chave){
      avo->esq = fix;
      fix->esq = novo;
      novo->dir = NULL;
    }else{
      avo->dir = fix;
      fix->dir = novo;
      novo->esq = NULL;
    }
    fix = novo;
    chave = fix->chave;
  }
  // CASO3
  fix = fix->pai;
  fix->pai = avo->pai;
  fix->cor = PRETO;
  avo->cor = VERMELHO;
  avo->pai = fix;
  if(avo->chave > chave){
    fix->dir = avo;
    avo->esq = NULL;
  }else{
    fix->esq = avo;
    avo->dir = NULL;
  }
  if(fix->pai != NULL){
    if((fix->pai)->chave > chave)
      (fix->pai)->esq = fix;
    else (fix->pai)->dir = fix;
  }else return fix;
  return PV;
}

void print(TpNodo* PV,int i){
  if(PV == NULL) return;
  for(int j=0; j<i && j < 15; printf(".."),j++);
  printf("%d %s\n",PV->chave, PV->cor ? "Vermelho" : "Preto");
  print(PV->esq, i+1);
  print(PV->dir, i+1);
} 

void menu(){
  printf("---------------------------------\n");
  printf("(1) - Inserir elemento.\n");
  printf("(2) - Imprimir arvore.\n");
  printf("(0) - Sair.\n");  
  printf("---------------------------------\n");
}

void ffree(TpNodo* PV){
  ffree(PV->esq);
  ffree(PV->dir);
  free(PV);
}
