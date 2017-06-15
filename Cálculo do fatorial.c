#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int valor;
	
	printf("Digite o valor a ser calculado seu fatorial:");
	scanf("%d",&valor);
	
	if(valor > 1)
	{
		int i=valor-1;
		for(;i>1;i--)
			valor *= i;
		printf("O valor do fatorial e %d",valor);
	}else
		printf((valor>=0)?"O valor do fatorial e 1":"O valor nao e valido");
}
