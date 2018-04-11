/*****************************************************************/
/*         Trabalho pratico 2 | Trabalho2 | MIEEC | 2017/18          */
/*****************************************************************/
/*                    FUNCOES A IMPLEMENTAR                      */
/*****************************************************************/

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

heap *heap_nova(int capacidade)
{
  heap *h = (heap *)malloc(sizeof(heap));
  int i=1;
  h->elementos = (elemento **)malloc(sizeof(elemento)); // vetor de apontadores para elementos
  h->capacidade = capacidade;
  h->tamanho = 0;
  h->elementos[0]=NULL;

  return h;
}

int heap_insere(heap *h, const char *texto, int prioridade)
{
  int i;
  elemento* aux= (elemento*)malloc(sizeof(elemento));
  aux->prioridade=prioridade;
  aux->valor=strdup(texto);

  if(h->elementos==NULL) return 0;

  if(h->tamanho == h->capacidade) return 0;
  h->tamanho++;

  h->elementos= realloc(h->elementos, (h->tamanho + 1) * sizeof(elemento));

  i= h->tamanho;

  for (i = h->tamanho; i > 1 && h->elementos[i/2]->prioridade > prioridade; i /= 2){
    h->elementos[i]= h->elementos[i/2];
  }

  h->elementos[i]=aux;

  return 1;
}

void heap_apaga(heap *h)
{
  for (int i = 1; i < h->tamanho; i++){
    free(h->elementos[i]->valor); //liberta todas as strings
    free(h->elementos[i]); //liberta o vetor;
  }

  free(h);
  return;
}

char *heap_remove(heap *h)
{
  if(h==NULL || h->tamanho == 0) return NULL;

  char * aux = strdup(h->elementos[1]->valor);

  // liberta a memoria do elemento que se vai retirar
  free(h->elementos[1]->valor);
  free(h->elementos[1]);

  int i = 1;

  if(h->tamanho > 1) {

    // compara os filhos e move o menor para cima
    while ((i*2)+1 <= h->tamanho){
      if(h->elementos[i*2]->prioridade > h->elementos[(i*2)+1]->prioridade){
        h->elementos[i] = h->elementos[(i*2)+1];
        i = (i*2)+1;
      }

      else if(h->elementos[i*2]->prioridade < h->elementos[(i*2)+1]->prioridade) {
        h->elementos[i] = h->elementos[(i*2)];
        i=i*2;
        }
    }

    h->elementos[i] = h->elementos[h->tamanho];
  }

  h->tamanho --;
  return aux;
}

heap *heap_constroi(elemento *v, int n_elementos)
{ 
  heap *HEAP;

  int i;

  HEAP = heap_nova(n_elementos);

  for (i=0; i < n_elementos; i++) {
    if( heap_insere(HEAP, v[i].valor, v[i].prioridade) == 0)
      return NULL;
  }

  return HEAP;
  // return NULL;
}

int heap_altera_prioridade(heap *h, int indice, int nova_prioridade)
{
  return -1;
}

void mostraHeap(heap *h, int indice)
{
  int i, nivel = 0;

  if (indice <= h->tamanho)
  {
    i = indice;
    while (i > 1)
    {
      i = i / 2;
      nivel++;
    }

    mostraHeap(h, indice * 2);

    for (i = 0; i < 3 * nivel; i++)
      printf("     ");

    printf("%s (%d)\n", h->elementos[indice]->valor, h->elementos[indice]->prioridade);

    mostraHeap(h, indice * 2 + 1);
  }
}
