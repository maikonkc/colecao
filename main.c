#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"

int cpm(const void* elm, const void* nome);

int main(){
  int ano;
  char *nomeCarro;
  float maxSpeed;
  Colecao *c = NULL;

	Carro *carro = NULL, **printado = NULL;
	Carro **addCarro = NULL;
	

  void* buscaNome; 
  void* remov;
  int aux, dest;
  int opc, tamColecao, excluir, coldest;
  void* removido;
  void *print;
 
  
  do{
    printf("\n----------------- MENU ----------------\n");
            printf("\t[1] - Criar uma colecao\n");
            printf("\t[2] - Inserir Carro\n");
            printf("\t[3] - Remover Carro\n");
            printf("\t[4] - Consultar Carro\n");
            printf("\t[5] - Listar Carros\n");
            printf("\t[6] - Destruir colecao\n");
            printf("\t[0] - Sair\n");
           printf("\n-----------------------------------------\n");
           printf("Digite a opcao desejada: ");
            scanf("%d",&opc);
    
    switch(opc){
      case 1: 
        printf("\n\tQual o tamanho da coleção que deseja inserir: ");
        scanf("%d", &tamColecao);
        if(tamColecao > 0 && (c == NULL) ){
          c = colCreate(tamColecao);
          if(c!=NULL){
            printf("\nA colecao foi criada com sucesso.\n");
          }
          else{
            printf("\nSinto Muito!Não foi possível criar a sua colecao.\n");
          }
        }
        else{
          printf("\nA colecao não pode ser criada\n");
        } 
      break;
      case 2:
        if(c!=NULL){
          carro = (Carro*)malloc(sizeof(Carro));
          carro->nomeCarro = (char*) malloc(sizeof(char)*50);
          if(carro != NULL){
            if(carro->nomeCarro != NULL){
              printf("\nInsira o nome: ");
              scanf("%s", carro->nomeCarro);
              fflush(stdin);
              printf("\nInsira o ano do carro: ");
              scanf("%d", &carro->ano);
              fflush(stdin);
              printf("\nInsira a velocidade maxima: ");
              scanf("%f", &carro->maxSpeed);
              fflush(stdin);
            }
            addCarro = (Carro**)malloc(sizeof(Carro*));

            if(addCarro != NULL){
              *addCarro = carro;
              aux = colInsert(c,(void*)addCarro);
              if(aux==TRUE){
                printf("\nCarro cadastrado com sucesso\n");
              }
              else{
                printf("\nFalha no cadastro, repita a operação\n");
              }
            }
            ///////////////////////////////////////
          }
        }
        else{
          printf("\nPrimeiro você deve criar a coleção\n");
        }
        break;
      case 3:
        if(c!= NULL && c->numItens>=0){
          nomeCarro = (char*) malloc(sizeof(char*)*50);
          printf("\nDigite o nome do carro que será removido: ");
          scanf("%s",nomeCarro);
          fflush(stdin);
          if(c->numItens >= 0){
            remov = colRemove(c,(void*)nomeCarro,cpm);
            if(remov == NULL){
                printf("\nO carro não foi encontrado sendo assim não pode ser retirado\n");
              }else{
                printf("\nCarro removido\n");
              }
          }else{
            printf("\nEstá colecao nao possui carros ainda\n");
          }
        }else{
          printf("\nSua colecao ainda nao foi criada\n");
        }
        break;
      case 4:
        if(c!= NULL && c->numItens>=0){
          nomeCarro = (char*) malloc(sizeof(char*)*50);
          printf("\nDigite o nome do carro que será buscado: ");
          scanf("%s",nomeCarro);
          fflush(stdin);
          if(c->numItens >= 0){
            buscaNome = colQuery(c, (void*)nomeCarro,cpm);
            if(buscaNome == NULL){
              printf("\nO carro não foi encontrado\n");
            }else{
                printf("\nCarro encontrado\n");
              } 
            fflush(stdin);
          }else{
            printf("\nEstá colecao nao possui carros ainda\n");
          }
        }else{
          printf("\nSua colecao ainda nao foi criada\n");
        }
        break;
      case 5: 
        if (c!=NULL && c->numItens >= 0){
          printf("\n------------ Colecao ---------------\n");
          for(int i = 0; i <= c->numItens; i++){
            print = printColecao(c, i);
            printado = (Carro**) print; 
            printf("\n Carro - nome:%s\tano:%d\tvelocidade:%.2f", (char*)(*printado)->nomeCarro, (int)(*printado)->ano, (float)(*printado)->maxSpeed);
          }
          printf("\n------------------------------------\n");
        }
        else{
          printf("\nPrimeiro voce deve criar uma colecao e inserir algum carro\n");
        }  
        break;
      case 6:
        printf("\nDeseja excluir colecao? (0-Nao 1-Sim): ");
        scanf("%d", &excluir);
        if(excluir == 0){
          break;
        }
        else{ 
          if(excluir == 1){
            if(c!=NULL){
              coldest = colDestroy(c);
              if(coldest == TRUE){
                printf("\nColecao destruida\n");
              }
              else{
                printf("\nFalha na destruicao da colecao\n");
              }
            } 
            else{
              printf("\nPrimeiro voce deve criar uma colecao\n");
            }
          }
        }
      break;
    }
  }while(opc!=0);
  
  printf("\nObrigada por usar nosso sistema\n");

    
}


// verifica se o nome do carro está na colecao
int cpm(const void* elm, const void* nome){ 
  int i=0, count=0;
  Colecao *col;
  Carro **c;
  col = (Colecao*) elm;
  c = (Carro**)col;
  char *alu = (char*) (*c)->nomeCarro;
  char *nom = (char*)nome ;
  for(i=0; i < strlen(alu); i++){
    if(alu[i] == nom[i]){
      count++;
    }
  }
  if(count == strlen(alu)){
    return TRUE;
  }else{
    return FALSE;
  }
}
