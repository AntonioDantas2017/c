#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int qtd, aux, nota, codigo;
	
	printf("Digite a quantidade de candidatos:\n");
	scanf("%d",&qtd);
	nota = -1;
	printf("Atencao: Digite os valores da lista do primeiro ao ultimo entregar o codigo.\n");
	
	int i=1;
	for(;i<=qtd;i++)
	{
		printf("Digite o valor da nota do %dº a entregar:\n",i);
		scanf("%d",&aux);
		if(aux >= 0)
		{
			if(aux > nota)
			{	
			nota = aux;
			printf("Digite o codigo do aluno:\n");
			scanf("%d",&codigo);
			}	
		}else
			i--;		
	}
	printf("O aluno de melhor desempenho foi %d e sua nota foi %d",codigo,nota);	
}
