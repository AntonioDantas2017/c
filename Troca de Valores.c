/*
AA 5.1 Troca de Valores
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int A, B, aux; //Declarando variáveis do tipo Inteiro
	int *pontA, *pontB; //Declarando Ponteiros do tipo Inteiro
	
	printf("Digite o valor de A:");
	scanf("%d",&A); //Recebendo valor de A
	printf("Digite o valor de B:");
	scanf("%d",&B); //Recebendo valor de B
	
	pontA = &A; //Apontando pontA no endereço da variável A
	pontB = &B; //Apontando pontB no endereço da variável B
	
	aux = *pontA; //Variável aux recebe conteúdo da variável que pontA está apontando
	*pontA = *pontB; //Variável A recebe conteúdo da variável que pontB está apontando
	*pontB = aux; //Variável B recebe o valor de aux
	
	printf("\nValor de A: %d \n Valor de B: %d\n",*pontA,*pontB);
	
	// finalização do programa principal
	system("PAUSE");
	return 0;
}
