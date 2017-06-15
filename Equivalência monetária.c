#include <stdio.h>
#include <stdlib.h>

/* 
Antonio Josivaldo Dantas Filho
RA 580961 - G7 
Programa para indentificar e informar a quantidade 
de moedas necess�rias para retornar um troco.
AA 2.1
*/

int main(int argc, char *argv[]) {
	//Declara��o das vari�veis
	float valor;
	int moedas,moedas2;
	
	//Recebendo informa��o do usu�rio
	printf("Digite o valor do troco:");
	scanf("%f", &valor);
	
	//Verifica se valor � v�lido para troco
	if(valor >= 0)
	{
		//Verifica quantidade de moedas de 1 real
		moedas = valor/1;
		valor-=moedas;
		
		//Verifica quantidade de moedas de 50 centavos
		moedas2 = (valor)/0.5;
		valor -= (moedas2*0.5);
		moedas += moedas2;
		
		//Verifica quantidade de moedas de 25 centavos
		moedas2 = valor/0.25;
		valor -= (moedas2*0.25);
		moedas += moedas2;
		
		//Verifica quantidade de moedas de 10 centavos
		moedas2 = valor/0.1;
		valor -= (moedas2*0.1);
		moedas += moedas2;
		
		//Verifica quantidade de moedas de 5 centavos
		moedas2 = valor/0.05;
		valor -= (moedas2*0.05);
		moedas += moedas2;
		
		//Verifica quantidade de moedas de 1 centavos
		moedas2 = valor/0.01;
		valor -= (moedas2*0.01);
		moedas += moedas2;
		
		//Informa Resultado
		printf("Quantidade de moedas: %d",moedas);
	}else
		printf("Valor informado incorreto.");
}