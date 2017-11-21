/*
INSERIR COMENTARIO
 */
#include<stdio.h>
#include<stdlib.h>

#include "RN.cpp"

int main(void){
  TpNodo* PV = NULL;
  int op,chave;
  do{
    menu();
    scanf("%d",&op);
    switch(op){
    case 1:
      printf("Digite o elemento a ser inserido: ");
      scanf("%d",&chave);
      PV = insere(PV, chave, NULL); PV->cor = PRETO;
      PV = fixup(PV, chave); PV->cor = PRETO;
      break;
    case 2:
      print(PV,1);
      break;
    case 0:
      break;
    default:
      printf("Insira uma opção valida!\n");
    }    
  }while(op != 0);
  ffree(PV);
  return 0;
}

