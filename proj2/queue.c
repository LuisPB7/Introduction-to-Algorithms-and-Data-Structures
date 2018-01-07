#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "queue.h"

void initializeVector(Queue vec, int N)
/* Inicializa um vetor de queues, de comprimento N-1, inicializando o tamanho de cada queue a 0 e colocando os ponteiros head e tail a apontar para NULL */

{
 	int i;
 	for (i=0;i<N;i++)
 	{
    		(vec+i)->head = NULL;
    		(vec+i)->tail = NULL;
    		(vec+i)->size = 0;
  	}
}

void insertItem(Item i, Queue vec)
/* Função que insere o Item i na queue do vetor vec correspondente ao seu receptor, fazendo as alterações necessárias ao tamanho e ponteiros head e tail da queue */

{
 	int r; 
	link novo;
	r = i->receptor;
 	novo = malloc(sizeof(struct node));	/* Aloca memória para um novo node que vai conter o Item i e um ponteiro para NULL */
 	novo -> item = i;
 	novo -> next = NULL;
  	if(((vec+r)->size) == 0)
 	{
  		((vec+r)->head) = ((vec+r)->tail) = novo;
  		((vec+r)->size) = 1;
 	}
 	else
 	{
  		(((vec+r)->tail)->next) = novo;
  		((vec+r)->tail) = novo;
  		((vec+r)->size)++;
 	}
}

void deleteHead(int u, Queue vec)
/* Função que elimina a head da queue u do vetor vec, fazendo as alterações necessárias a essa queue */

{
 	if(((vec+u)->size) > 1)
 	{
  		link aux = (((vec+u)->head)->next);	/* O aux é usado para guardarmos o ponteiro para nova head */
  		free(((vec+u)->head)->item);
  		free((vec+u)->head);
  		((vec+u)->head) = aux;
  		((vec+u)->size)--;
 	}  
 	else if (((vec+u)->size) == 1)
 	{	
  		free(((vec+u)->head)->item);
  		free((vec+u)->head);
  		((vec+u)->head) = NULL;
  		((vec+u)->tail) = NULL;
  		((vec+u)->size) = 0;
 	}
}

void kill(int u, Queue vec)
/* Função que usa deleteHead para apagar os nodes da queue u do vetor vec */

{
 	while((vec+u)->size)
 	{
  		deleteHead(u, vec);
 	}
}

void printHead(int u, Queue vec)
/* Função que imprime o primeiro node da queue u do vetor vec */

{
 	if(((vec+u)->size)==0)
 	{
  		printf("NULL\n");
 	}
 	else
 	{
  		printf("%d %d %s\n", ((((vec+u)->head)->item)->receptor), ((((vec+u)->head)->item)->emissor), ((((vec+u)->head)->item)->pmsg));
 	} 
}

void listMessages(int u, Queue vec)
/* Função que imprime a informação contida nos Items da queue u do vetor vec */

{
 	link aux;
 	aux = (vec+u)->head; 
 	if(((vec+u)->size) == 0)
 	{
  		printf("NULL\n");
 	}
 	while (aux)
 	{
  		printf("%d %d %s\n", (((aux->item)->receptor)), (((aux->item)->emissor)), (((aux->item)->pmsg)));
  		aux = aux->next;
 	}
}

void getItems(int u, Queue vec, Item items)
/* Função que percorre a queue u do vetor vec, colocando cada Item no vetor items */

{ 
 	int i;
 	link aux;
 	i=0;
 	aux = (vec+u)->head;
 	while (aux)
	{
	  	(items+i)->emissor = (aux->item)->emissor;
	  	(items+i)->receptor = (aux->item)->receptor;
	  	(items+i)->pmsg = (aux->item) -> pmsg;
	  	aux = aux->next;
	  	i++;
	} 
}

void deleteQueues(int users, Queue vec)
/* Função que apaga toda a informação de cada queue do vetor vec */

{
	int x;
	x=0;
	while (x<users)
	{
		if(((vec+x)->head == NULL))
		{
			x++;
		}
		else
		{
			kill(x,vec);
			x++;
		}
	}
}
