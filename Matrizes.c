/*
AA 3.2 – Prática de desenvolvimento 2
Objetivo: Fazer a alocação dinâmica de matrizes.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação	

Matrizes

Objetivos
Fazer a alocação dinâmica de matrizes.

Informações gerais
A multiplicação de matrizes é uma operação importante, com muitas aplicações.

Especificação
Escreva um programa em C que realize as seguintes tarefas:

Leia uma matriz, de dimensões MxN
Calcule e escreva sua transposta, que terá dimensões NxM
Calcule e escreva a multiplicação da transposta pela matriz original, que terá dimensões NxN
Cada matriz que for utilizada deve ser alocada dinamicamente, conforme suas dimensões. Todos os dados da matriz devem ser reais.
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    int l, c, i, j; //Auxiliares

	printf("Digite LINHAS COLUNAS da matriz:");
    scanf("%d %d",&l,&c); //Recebe do Teclado
    
    float **m; //Ponteiro de ponteiro
	m = malloc(l * sizeof(float *)); //Alocação Linhas
	for(i=0;i<l;i++) 
		m[i] = malloc(c * sizeof(float)); //Alocação Colunas
	
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
	aux = malloc(c * sizeof(float *)); //Alocação Linhas
	for(i=0;i<c;i++)
		aux[i] = malloc(l * sizeof(float)); //Alocação Colunas
	
	//Matriz Transposta
	for(i=0;i<l;i++){
		for(j=0;j<c;j++)
			aux[j][i] = m[i][j]; //Trasnposição da Matriz
	}
	
	printf("\nMatriz transposta:\n");
	for(i=0;i<c;i++){
		for(j=0;j<l;j++)
			printf("%f ",aux[i][j]);
		printf("\n");
	}
	
	
	float **aux2;//Ponteiro de ponteiro
	aux2 = malloc(c * sizeof(float *)); //Alocação Linhas
	for(i=0;i<c;i++)
		aux2[i] = malloc(c * sizeof(float)); //Alocação Colunas
	
	//Multiplicação das Matrizes
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
	
	//Liberação da memória
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

