#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

Item newItem(int sender, int receiver)
/* Função que aloca memória para um Item, preenchendo-o com os argumentos da função */

{
 	Item new = malloc(sizeof(struct mensagem));
 	new->emissor = sender;
 	new->receptor = receiver;
 	return new;
}

void readMessage(Item item, int max)
/* Função que lê a mensagem enviada pelo utilizador e aloca o espaço em memória necessário  */

{
  	int  i, c;
  	char* input;
  	input = malloc(MSG_DIM*sizeof(char));		/* Aloca memória para o número máximo de caracteres */
  	i = 0;
	for (i = 0; i < max-1 && (c=getchar())!= EOF && c !='\n'; i++)
  	{
    		input[i]=c;
  	}
  	input[i] = '\0';
  	input = realloc(input, strlen(input)+1);	/* Sabido o comprimento da mensagem, ajusta-se a quantidade de memória alocada */
  	item->pmsg=input;
}

int compareItems(Item a, Item b)
/* Função de comparação do qsort, que recebe 2 Items e compara as suas mensagens. Devolve 1 se A for maior que B e -1 caso contrário */

{
 	if (strcmp(a->pmsg,b->pmsg)==0)
	{
  		if(a->emissor < b->emissor)	/* No caso das mensagens terem o mesmo tamanho, a mensagem com menor emissor é a menor */
		{
   			return -1;
  		}
  		else
		{
   			return 1;
  		}
 	}
 	else if (strcmp(a->pmsg,b->pmsg)<0)
	{
  		return -1;
 	}
 	else
	{
  		return 1;
 	}
}

void printItems(int size, Item items)
/* Função que imprime cada item do vetor items */

{
 	int i;
 	for(i=0; i<size;i++)
	{
  		printf("%d %d %s\n",(items+i)->receptor,(items+i)->emissor, (items+i)->pmsg);
 	} 
}
