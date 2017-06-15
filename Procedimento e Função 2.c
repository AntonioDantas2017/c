/*
AA 5.3 Raiz Quadrada
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Defini��o da biblioteca com fun��es matem�ticas

#define TAMANHO 100 //Constante do tamanho do vetor

float calculaRaiz(float numero) //Assinatura da fun��o
{
	return sqrt(numero); //Retorno da fun��o
}

int main(int argc, char *argv[])
{
	float numeros[TAMANHO];
	int i;
	
	for(i=0;i<TAMANHO;i++)
	{
		printf("Digite o %d� numero:",i+1);
		scanf("%f",&numeros[i]); //Recebendo dados do teclado
		printf("A raiz quadrada de %f e:%f\n\n",numeros[i],calculaRaiz(numeros[i])); //Chamada da fun��o
	}

	// finaliza��o do programa principal
	system("PAUSE");
	return 0;
}

