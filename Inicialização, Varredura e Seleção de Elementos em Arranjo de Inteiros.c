/*
AA 3.4 Programa destacar um elemento dentro de um intevalo em um arranjo unidimensional
Antonio Josivaldo Dantas Filho
Ufscar - RA 580961 - G7 - Sistemas de Informa��o
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// declara��o vari�veis 
	int tamanho, i;	
	
	//Recebendo tamanho do vetor
	printf("Favor digite o tamanho do arranjo:");
	scanf("%d",&tamanho);	
	
	// declara��o do arranjo unidimensional
	int vetor[tamanho];	
	
	for(i=0;i<tamanho;i++)
	{
		//Recebendo valores
		printf("Favor digite um numero para a posicao[%d]:",i);
		scanf("%d",&vetor[i]);
	}
	
	//Exibir Resultados
	for(i=0;i<tamanho;i++)
	{
		printf("\nElemento da posicao [%d] = %d",i,vetor[i]);
		if(vetor[i] >= 10 && vetor[i] <=30)
			printf(" -> Destaque"); //Destacando filtro
	}
	
	// finaliza��o do programa principal
	printf("\n\nSistema Finalizado\n");
	system("PAUSE");
	return 0;
}
