/*
AA 3.2 � Pr�tica de desenvolvimento 2
Objetivo: Fazer a aloca��o din�mica de matrizes.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o	

Matrizes

Objetivos
Fazer a aloca��o din�mica de matrizes.

Informa��es gerais
A multiplica��o de matrizes � uma opera��o importante, com muitas aplica��es.

Especifica��o
Escreva um programa em C que realize as seguintes tarefas:

Leia uma matriz, de dimens�es MxN
Calcule e escreva sua transposta, que ter� dimens�es NxM
Calcule e escreva a multiplica��o da transposta pela matriz original, que ter� dimens�es NxN
Cada matriz que for utilizada deve ser alocada dinamicamente, conforme suas dimens�es. Todos os dados da matriz devem ser reais.
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    int l, c, i, j; //Auxiliares

	printf("Digite LINHAS COLUNAS da matriz:");
    scanf("%d %d",&l,&c); //Recebe do Teclado
    
    float **m; //Ponteiro de ponteiro
	m = malloc(l * sizeof(float *)); //Aloca��o Linhas
	for(i=0;i<l;i++) 
		m[i] = malloc(c * sizeof(float)); //Aloca��o Colunas
	
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("Digite o valor da matriz na posicao [%d][%d]: ",i,j);
			scanf("%f",&m[i][j]); //Recebe do Teclado
		}
	}
	
	printf("\n\n");
	
	printf("\nMatriz Original:\n");
	for(i=0;i<l;i++){
		for(j=0;j<c;j++)
			printf("%f ",m[i][j]);
		printf("\n");
	}
	
	float **aux;//Ponteiro de ponteiro
	aux = malloc(c * sizeof(float *)); //Aloca��o Linhas
	for(i=0;i<c;i++)
		aux[i] = malloc(l * sizeof(float)); //Aloca��o Colunas
	
	//Matriz Transposta
	for(i=0;i<l;i++){
		for(j=0;j<c;j++)
			aux[j][i] = m[i][j]; //Trasnposi��o da Matriz
	}
	
	printf("\nMatriz transposta:\n");
	for(i=0;i<c;i++){
		for(j=0;j<l;j++)
			printf("%f ",aux[i][j]);
		printf("\n");
	}
	
	
	float **aux2;//Ponteiro de ponteiro
	aux2 = malloc(c * sizeof(float *)); //Aloca��o Linhas
	for(i=0;i<c;i++)
		aux2[i] = malloc(c * sizeof(float)); //Aloca��o Colunas
	
	//Multiplica��o das Matrizes
	int linha, coluna;
	float soma;
	for(linha=0; linha<c; linha++){
	    for(coluna=0; coluna<c; coluna++){
	    	soma=0;
	      	for(i=0; i<l; i++) //Linhas pelas colunas
		  		soma += aux[linha][i] * m[i][coluna]; //Soma do Produto
	      	aux2[linha][coluna]=soma;
		}
	} 
	
	printf("\nMatrizes Multiplicadas:\n");
	for(i=0;i<c;i++){
		for(j=0;j<c;j++)
			printf("%f ",aux2[i][j]);
		printf("\n");
	}
	
	//Libera��o da mem�ria
	free(m[0]);
	free(m);
	
	free(aux[0]);
	free(aux);
	
	free(aux2[0]);
	free(aux2);
	
	//Fim do Programa
	printf("Programa finalizado!");
	system("pause");
	return 0;
}

