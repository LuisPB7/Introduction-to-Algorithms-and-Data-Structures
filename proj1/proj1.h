#ifndef _proj1_h
#define _proj1_

#define NUMPAISES 28
#define NUMPARTIDOS 12
#define DEPUTADOS 751
#define MAXSTRING 58

void iniciaMatrizParc(int m[NUMPAISES][NUMPARTIDOS], int pais);
void copiaMatriz (float destmat[NUMPAISES][NUMPARTIDOS], int srcmat[NUMPAISES][NUMPARTIDOS]);
void mostraPais(int n, char p[][3],float m[NUMPAISES][NUMPARTIDOS]);
void iniciaMatriz(int m[NUMPAISES][NUMPARTIDOS]);
void escreveMatriz(float m[NUMPAISES][NUMPARTIDOS], char p[][3]);
void iniciaSomas(int s[NUMPARTIDOS]);
void preencheSomas(float m[NUMPAISES][NUMPARTIDOS], int s[NUMPARTIDOS]);
void escreveSomas(int s[NUMPARTIDOS]);
void aplicaHondt (float mat[NUMPAISES][NUMPARTIDOS], int ele[NUMPAISES][NUMPARTIDOS], int vot[NUMPAISES][NUMPARTIDOS], int dep, int p);

#endif
