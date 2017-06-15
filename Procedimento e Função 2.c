/*
AA 5.3 Raiz Quadrada
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Definição da biblioteca com funções matemáticas

#define TAMANHO 100 //Constante do tamanho do vetor

float calculaRaiz(float numero) //Assinatura da função
{
	return sqrt(numero); //Retorno da função
}

int main(int argc, char *argv[])
{
	float numeros[TAMANHO];
	int i;
	
	for(i=0;i<TAMANHO;i++)
	{
		printf("Digite o %dº numero:",i+1);
		scanf("%f",&numeros[i]); //Recebendo dados do teclado
		printf("A raiz quadrada de %f e:%f\n\n",numeros[i],calculaRaiz(numeros[i])); //Chamada da função
	}

	// finalização do programa principal
	system("PAUSE");
	return 0;
}

