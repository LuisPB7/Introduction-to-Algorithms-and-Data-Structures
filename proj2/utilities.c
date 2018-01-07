#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readCommand(char input[], int max)
/* Função que lê o comando do utilizador */

{
 	int  i, c;
  	i = 0;
  	for (i = 0; i < max-1 && (c=getchar())!= EOF && c !='\n' && c != ' '; i++)
  	{
    		input[i] = c; 
  	}
  	input[i] = '\0';
}


