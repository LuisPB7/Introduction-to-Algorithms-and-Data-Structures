/******************************************************************************************
 *	Projecto: Eleicoes Europeias
 *-----------------------------------------
 *      
 *	Antonio Tavares - nº 78122 
 *      Luis Borges	- nº 78349
 *	Paulo Ritto	- nº 78929
 *
 ******************************************************************************************/



#include <stdio.h>
#include <string.h>
#include "proj1.h"

int main()
{
	/*		DECLARACAO DE VARIAVEIS		*/
	char command;
 	char paises[][3] = {"DE", "AT", "BE", "BG", "CY", "HR", "DK", "SK", "SI", "ES", "EE", "FI", "FR", "GR", "HU", "IE", "IT", "LV", "LT", "LU", "MT", "NL", "PL", "PT", "GB", "CZ", "RO", "SE"};
 	int nPais, partido, votos, pais, maxDeputados,votacao[NUMPAISES][NUMPARTIDOS], eleitos[NUMPAISES][NUMPARTIDOS], somas[NUMPARTIDOS];
	float matrizFloat[NUMPAISES][NUMPARTIDOS];
 	int maxDeps[NUMPAISES] = {96,18,21,17,6,11,13,13,8,54,6,13,74,21,21,11,73,8,11,6,6,26,51,21,73,21,32,20};

	/*		INICIALIZACAO DAS MATRIZES	*/
     	iniciaMatriz(votacao);
     	iniciaMatriz(eleitos);

	/*		ESCOLHA DE INPUT		*/
	while ((command = getchar()) != 'x') /* Le o comando */
	{ 
        	switch (command) 
        	{
       	 	case '+':
         		scanf("%d %d %d", &pais,&partido,&votos);
  			    iniciaMatrizParc(eleitos, pais); /*serve para limpar um pais*/
       			maxDeputados = maxDeps[pais-1];
       			votacao[pais-1][partido-1] = votacao[pais-1][partido-1] + votos; /*vamos à matriz votacao meter os votos*/
             	copiaMatriz(matrizFloat,votacao); /*copiamos a matriz votacao para a matrizFloat */
      			aplicaHondt (matrizFloat, eleitos, votacao, maxDeputados, pais);     
  			    copiaMatriz(matrizFloat,eleitos); /*copiamos a matriz dos eleitos para matrizFloat, a matriz a apresentar*/
            		break;
        	case 'm':
             	scanf("%d", &nPais);
       			mostraPais(nPais, paises, matrizFloat);
            		break;
        	case 'e':
             	escreveMatriz(matrizFloat, paises);
     			iniciaSomas(somas);
     			preencheSomas(matrizFloat, somas);
     			escreveSomas(somas);
            		break;
        	default:
             		printf("ERRO: Comando desconhecido\n");
        	}
        	getchar(); /* Le o '\n' introduzido pelo utilizador */
    	}
    	return 0;
}


/*			FUNCOES AUXILIARES		*/



void iniciaMatrizParc(int m[NUMPAISES][NUMPARTIDOS], int pais)
/* Funcao que coloca todos os valores de uma linha especifica de uma matriz a 0 */

{
	int j;
   	for(j=0; j< NUMPARTIDOS; j++)
 	{
  		m[pais-1][j] = 0;
      	} 
}


void copiaMatriz (float destmat[NUMPAISES][NUMPARTIDOS], int srcmat[NUMPAISES][NUMPARTIDOS]) 
/* Funcao que copia os dados de uma matriz para outra matriz */

{
	int i, j;
  	for (i=0; i<NUMPAISES; i=i+1)
	{
    		for (j=0; j<NUMPARTIDOS; j=j+1)
		{
      			destmat[i][j] = srcmat[i][j];
		}
	}
}


void aplicaHondt (float mat[NUMPAISES][NUMPARTIDOS], int ele[NUMPAISES][NUMPARTIDOS], int vot[NUMPAISES][NUMPARTIDOS], int dep, int p) 
/* Funcao que calcula o numero de eleitos a atribuir a um partido num certo pais, recorrendo ao Metodo de Hondt */

{
	int j,jMaior,el;
	float maior;
	el = 0;
	jMaior = 0;
    maior = 0.0;
   	while (el != dep)
  	{
     		for(j=0; j < NUMPARTIDOS; j++)	/* Descobre o partido com maior quociente de Hondt de um pais e guarda o elemento e indice desse elemento */
   		{
    			if(mat[p-1][j] > maior)
    			{
         			maior = mat[p-1][j];
         			jMaior = j;
       			}
   		}
   		for(j=0; j < NUMPARTIDOS; j++)	/* Verifica se existem mais partidos com o maior quociente de Hondt e caso existam, guarda o elemento e indice do partido com menos deputados eleitos */
   		{
    			if(mat[p-1][j] == mat[p-1][jMaior])
    			{
     				if(ele[p-1][j] < ele[p-1][jMaior])
     				{
      					maior = mat[p-1][j];
          				jMaior = j;
     				}
    			} 
   		}
		/* Aplica o Metodo de Hondt ao elemento maior, previamente guardado */
     		ele[p-1][jMaior] = ele[p-1][jMaior] + 1;						
     		maior = (float)(vot[p-1][jMaior]) / (float)(ele[p-1][jMaior] + 1);	 
   		    mat[p-1][jMaior] = maior;						 
     		el = el + 1;						 
  	}
}


void mostraPais(int n, char p[][3],float m[NUMPAISES][NUMPARTIDOS])
/* Funcao que imprime o nº de eleitos de cada partido, de um pais n */

{
	int j;
  	printf("   EPP PES LDE EGP ECR ELP ELD EDP EAF EMN ECP AED\n");
  	printf("%s", p[n-1]);
  	for(j=0; j<NUMPARTIDOS; j++)
 	{
    		printf(" %3d", (int)m[n-1][j]);
   	}
  	printf("\n");
}
 
 
void iniciaMatriz(int m[NUMPAISES][NUMPARTIDOS])
/* Funcao que coloca todos os valores de uma matriz a 0 */

{
	int i,j;
 	for(i=0;i<NUMPAISES; i++)
 	{
  		for(j=0; j<NUMPARTIDOS; j++)
  		{
      			m[i][j] = 0;
     		} 
    	}
}


void escreveMatriz(float m[NUMPAISES][NUMPARTIDOS], char p[][3])
/* Funcao que imprime a matriz dos paises e partidos com os valores de eleitos correspondentes */

{
	int i,j;
	printf("   EPP PES LDE EGP ECR ELP ELD EDP EAF EMN ECP AED\n");
  	for(i=0;i<NUMPAISES; i++)
 	{
		printf("%s", p[i]);
    		for(j=0; j<NUMPARTIDOS; j++)
  		{
      			printf(" %3d", (int)m[i][j]);

			
     		}
    		printf("\n");
   	}
}


void iniciaSomas(int s[NUMPARTIDOS])
/* Funcao que coloca todos os valores do vector Soma a 0 */

{
	int i;
 	for (i=0; i<NUMPARTIDOS;i++)
 	{
    		s[i]=0;
  	}
}


void preencheSomas(float m[NUMPAISES][NUMPARTIDOS], int s[NUMPARTIDOS])
/* Funcao que preenche o vector Soma com as somas dos eleitos de cada partido */

{
	int i, j;
 	for (j=0;j<NUMPARTIDOS;j++)
 	{
  		for(i=0;i<NUMPAISES;i++)
  		{
     			s[j] = s[j] + (int)m[i][j];  
  		}
 	}
}


void escreveSomas(int s[NUMPARTIDOS])
/* Funcao que imprime a linha com os valores do vector Soma */

{
	int pa;
	printf("TE");
      	for(pa=0; pa<NUMPARTIDOS; pa++)
	{
         	printf(" %3d", s[pa]);
      	}
	printf("\n");
}
