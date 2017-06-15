/*
AA 3.2 Programa para encontrar o valor e a posição do menor numero em um vetor
Antonio Josivaldo Dantas Filho
Ufscar - RA 580961 - G7 - Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

int main(int argc, char *argv[])
{
	// declaração variáveis 
	int vetor[TAMANHO];
	int i, menor, posicao;
	
	//Limpando variaveis
	posicao = 0;
	
	//Recebendo o primeiro valor
	printf("Favor digite um numero:");
	scanf("%d",&vetor[0]);
	menor = vetor[0];
	
	for(i=1;i<TAMANHO;i++)
	{
		//Recebendo outros valores
		printf("Favor digite um numero:");
		scanf("%d",&vetor[i]);
		
		if(vetor[i] < menor) //Conferindo se menor que o menor ate o momento
		{
			menor = vetor[i]; //Atribuindo novo menor 
			posicao = i; //Atribuindo posicao novo menor 
		}
	}
	
	//Exibir Resultados
	printf("O menor elemento do vetor e %d e sua posicao dentro do vetor e [%d]", menor, posicao);
	
	// finalização do programa principal
	printf("\nSistema Finalizado\n");
	system("PAUSE");
	return 0;
}
