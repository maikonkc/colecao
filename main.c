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

	Carro *carro = NULL, **printado = NULL, *print;
	Carro **addCarro = NULL;
	

  void* buscaNome; 
  void* remove;
  int aux;
  int opcao, tamanho, excluir, destruir;
  void* removido;
 
  
  do{
    printf("\n----------------- MENU ----------------\n");
            printf("[1] - Criar uma colecao\n");
            printf("[2] - Inserir Carro\n");
            printf("[3] - Remover Carro\n");
            printf("[4] - Consultar Carro\n");
            printf("[5] - Listar Carros\n");
            printf("[6] - Destruir colecao\n");
            printf("[0] - Sair\n");
           printf("\n-----------------------------------------\n");
           printf("Digite a opcao desejada: ");
            scanf("%d",&opcao);
    
    switch(opcao){
      case 1: 
        printf("\nQual o tamanho da coleção que deseja inserir: ");
        scanf("%d", &tamanho);
        if(tamanho > 0 && (c == NULL) ){
          c = colCreate(tamanho);
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
                printf("\nFalha no cadastro\n");
              }
            }
          }
        }
        else{
          printf("\nPrimeiro crie a coleção\n");
        }
        break;
      case 3:
        if(c!= NULL && c->numItens>=0){
          nomeCarro = (char*) malloc(sizeof(char*)*50);
          printf("\nDigite o nome do carro que será removido: ");
          scanf("%s",nomeCarro);
          fflush(stdin);
          if(c->numItens >= 0){
            remove = colRemove(c,(void*)nomeCarro,cpm);
            if(remove == NULL){
                printf("\nO carro nao foi encontrado\n");
              }else{
                printf("\nCarro removido\n");
              }
          }else{
            printf("\nEsta colecao nao possui carros ainda\n");
          }
        }else{
          printf("\nSua colecao ainda nao foi criada\n");
        }
        break;
      case 4:
        if(c!= NULL && c->numItens>=0){
          nomeCarro = (char*) malloc(sizeof(char*)*50);
          printf("\nDigite o nome do carro que sera buscado: ");
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
            printf("\nEsta colecao nao possui carros ainda\n");
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
						printf("Carro [%d]", i);
            printf("\n Nome:%s \n Ano:%d \n Velocidade:%.2f", (char*)(*printado)->nomeCarro, (int)(*printado)->ano, (float)(*printado)->maxSpeed);
          }
          printf("\n------------------------------------\n");
        }
        else{
          printf("\nPrimeiro crie a colecao e insera um\n");
        }  
        break;
      case 6:
        printf("\nDeseja excluir colecao? (1-Sim 0-Nao): ");
        scanf("%d", &excluir);
        if(excluir == 0){
          break;
        }
        else{ 
          if(excluir == 1){
            if(c!=NULL){
              destruir = colDestroy(c);
              if(destruir == TRUE){
                printf("\nColecao destruida\n");
              }
              else{
                printf("\nFalha ao destruit\n");
              }
            } 
            else{
              printf("\nPrimeiro crie a colecao\n");
            }
          }
        }
      break;
    }
  }while(opcao!=0);
  
  printf("\nObrigada por usar nosso sistema\n");

    
}

// verifica se o nome do carro está na colecao
int cpm(const void* elm, const void* nome){ 
  int i=0, count=0;
  Colecao *col;
  Carro **c;
  col = (Colecao*) elm;
  c = (Carro**)col;
  char *car = (char*) (*c)->nomeCarro;
  char *nom = (char*)nome ;
  for(i=0; i < strlen(car); i++){
    if(car[i] == nom[i]){
      count++;
    }
  }
  if(count == strlen(car)){
    return TRUE;
  }else{
    return FALSE;
  }
}
