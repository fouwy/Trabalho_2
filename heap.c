/*****************************************************************/
/*         Trabalho pratico 2 | PROG2 | MIEEC | 2017/18          */
/*****************************************************************/
/*                    FUNCOES A IMPLEMENTAR                      */
/*****************************************************************/

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50 //capacidade da string valor

heap* heap_nova(int capacidade)
{
  heap *new;

  /*aloca memoria para a estrutura heap*/
  new = (heap*)malloc(sizeof(heap));
  if(new == NULL) {
    return NULL;
  }

  new->capacidade = capacidade;
  new->tamanho = 0;

  /*aloca memoria para o array de pointers*/
  new->elementos = (elemento**)malloc(capacidade * sizeof(elemento*));

  /*aloca memoria para o array de structs*/
  for( int i = 0; i < capacidade; i++ ) {
    new->elementos[i] = malloc(sizeof(elemento));
    new->elementos[i]->valor = (char*)malloc(sizeof(char) * N);
  }

  return new;
}

int heap_insere(heap * h, const char * texto, int prioridade)
{ 
  int i;

  /* Verifica se a heap está cheia; Se estiver retorna 0; */
  if( h->tamanho == h->capacidade ) {
    return 0;
  }
  
  h->tamanho++;

  // if(h->tamanho == 1) {
  //   h->elementos[1]->prioridade = prioridade;
  //   strcpy( h->elementos[1]->valor, texto );

  //   return 1;
  // }

  for( i = h->tamanho; i > 1 && h->elementos[i/2]->prioridade > prioridade; i /= 2 ) {
    h->elementos[i] = h->elementos[i/2];
  }

  h->elementos[i]->prioridade = prioridade;
  strcpy( h->elementos[i]->valor, texto );

  return 1;
}

void heap_apaga(heap *h)
{
  return;
}

char* heap_remove(heap * h)
{
  return NULL;
}

heap* heap_constroi(elemento* v, int n_elementos)
{
  return NULL;
}

int heap_altera_prioridade(heap *h, int indice, int nova_prioridade)
{
  return -1;
}

void mostraHeap(heap *h, int indice)
{
  int i, nivel = 0;
  
  if (indice < h->tamanho)
  {
    i = indice;
    while(i > 1)
    {
      i = i/2;
      nivel++;
    }
    
    mostraHeap(h, indice*2);
    
    for(i = 0; i < 3 * nivel; i++)
      printf("     ");
    
    printf("%s (%d)\n",h->elementos[indice]->valor, h->elementos[indice]->prioridade);
    
    mostraHeap(h, indice*2+1);
  }
}