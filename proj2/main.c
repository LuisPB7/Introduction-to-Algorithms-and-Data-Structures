/******************************************************************************************
 *	Projecto: Processamento de Mensagens
 *-----------------------------------------
 *      
 *	António Tavares - nº 78122 
 *      Luís Borges	- nº 78349
 *	Paulo Ritto	- nº 78929
 *
 ******************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "queue.h"
#include "utilities.h"

#define INPUT_DIM 12
#define MSG_DIM 501


int main()
{
/*	DECLARAÇÃO DE VARIÁVEIS		*/
 	char input[INPUT_DIM]={'\0'};
 	int users, e, r, u;
 	Item i, items;
 	Queue vec;
	users = 0;
 	scanf("%d", &users);
 	vec = malloc(sizeof(struct queue)*users);

/*	INICIALIZA VETOR DE QUEUES, LÊ E PROCESSA INPUT DO UTILIZADOR	*/
 	initializeVector(vec,users);
 	while (strcmp(input,"quit")!=0)
 	{
  		readCommand(input,INPUT_DIM);
  		if (strcmp(input,"send")==0)
  		{
   			scanf("%d %d ", &e, &r);
   			i = newItem(e,r);
   			readMessage(i, MSG_DIM);
   			insertItem(i,vec);
  		}
  		else if (strcmp(input,"process")==0)
  		{
   			scanf("%d", &u);
   			printHead(u,vec);
   			deleteHead(u, vec);
  		}
  		else if (strcmp(input,"kill")==0)
  		{		
   			scanf("%d", &u);
   			kill(u,vec);
  		}
  		else if (strcmp(input,"list")==0)
  		{
   			scanf("%d", &u);
   			listMessages(u, vec);
  		}  
  		else if (strcmp(input,"listsorted")==0)
		{
   			scanf("%d", &u);
    			if(((vec+u)->size)==0)
			{
     				printf("NULL\n");
    			}
    			else
			{
     				items = malloc(sizeof(struct mensagem) * (vec+u)->size);
     				getItems(u,vec,items);
     				qsort(items, (vec+u)->size, sizeof(struct mensagem), (int(*)(const void*,const void*))compareItems);
     				printItems((vec+u)->size,items); 
     				free(items);
   			}		
  		}
 	}

/*	LIBERTA A MEMÓRIA UTILIZADA	*/
	deleteQueues(users, vec);
 	free(vec);
	return 0;
}
