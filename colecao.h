#ifndef  _COLECAO_H_
#define  _COLECAO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct _carro_
{
  int ano;
  char *nomeCarro; 
  float maxSpeed;
} Carro;

typedef struct _colecao_
{
  int maxItens;
  int numItens;
  int curItem;
  void **item;
} Colecao;


Colecao *colCreate(int maxItens);
int colInsert(Colecao *c, void* item);
int cpm(const void* elm, const void* nome);
void *colQuery(Colecao *c, void* key,int(*cmp)(const void*, const void*));
int colDestroy(Colecao *c);
void *colRemove(Colecao *c, void* key,int(*cmpNomeCarro)(const void*, const void*));
void *printColecao(Colecao *c, int i);

#endif
