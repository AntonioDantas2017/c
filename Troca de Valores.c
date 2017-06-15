/*
AA 5.1 Troca de Valores
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int A, B, aux; //Declarando vari�veis do tipo Inteiro
	int *pontA, *pontB; //Declarando Ponteiros do tipo Inteiro
	
	printf("Digite o valor de A:");
	scanf("%d",&A); //Recebendo valor de A
	printf("Digite o valor de B:");
	scanf("%d",&B); //Recebendo valor de B
	
	pontA = &A; //Apontando pontA no endere�o da vari�vel A
	pontB = &B; //Apontando pontB no endere�o da vari�vel B
	
	aux = *pontA; //Vari�vel aux recebe conte�do da vari�vel que pontA est� apontando
	*pontA = *pontB; //Vari�vel A recebe conte�do da vari�vel que pontB est� apontando
	*pontB = aux; //Vari�vel B recebe o valor de aux
	
	printf("\nValor de A: %d \n Valor de B: %d\n",*pontA,*pontB);
	
	// finaliza��o do programa principal
	system("PAUSE");
	return 0;
}
