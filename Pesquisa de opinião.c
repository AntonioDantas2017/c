#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float nota2, resp11, resp12, resp13, nota, resp31, resp32, resp33, resp34;
	int aux, aux2, qtd;
	
	qtd = resp11 = resp12 = resp13 = nota = resp31 = resp32 = resp33 = resp34 = 0;
	
	printf("Gostou do sabor do suco?:");
	scanf("%d",&aux);
	while(aux != 4){
		qtd++;
		printf("Que nota daria para o sabor, de 0 (ruim) a 10 (excelente), sem usar casas decimais?");
		scanf("%d",&aux2);
		if(aux==2)
		{
			resp12++;
			nota+=aux2;
			nota2+=aux2;	
		}
		else{
			(aux==1)?resp11++:resp13++;
			nota+=aux2;
		}
		printf("Qual das embalagens gostou mais?");
		scanf("%d",&aux);
		switch(aux){
			case 1: resp31++; break;
			case 2: resp32++; break;
			case 3: resp33++; break;
			case 4: resp34++; break;
		}
		system("cls");
		printf("Novo Voluntario\nGostou do sabor do suco?:");
		scanf("%d",&aux);
	}
	
	if(qtd>0)
	{
		printf("\nForam entrevistadas %d pessoa(s)",qtd);
		printf("\nPorcentagem de respostas para pergunta 1 e alternativa 1: %f",((resp11/qtd)*100));
		printf("\nPorcentagem de respostas para pergunta 1 e alternativa 2: %f",((resp12/qtd)*100));
		printf("\nPorcentagem de respostas para pergunta 1 e alternativa 3: %f",((resp13/qtd)*100));
		printf("\nA nota média dada para o suco para todos os participantes: %f",(nota/qtd));
		printf("\nA nota média dada para o suco apenas para os que responderam 'Nao' na primeira pergunta: %f",(nota2/qtd));
		aux = 0;
				
		
		if(resp31 >= resp32)
		{
			if(resp31 >= resp33)
			{
				if(resp31 >= resp34)
				{
					printf("\nUma embalagem preferida pela maioria: 1");
					if(resp31 == resp32)
						printf("\nUma embalagem preferida pela maioria: 2");
					if(resp31 == resp33)
						printf("\nUma embalagem preferida pela maioria: 3");
					if(resp31 == resp34)
						printf("\nUma embalagem preferida pela maioria: 4");
				}
			}
		}else{
			if(resp32 >= resp33)
			{
				if(resp32 >= resp34)
				{
					printf("\nUma embalagem preferida pela maioria: 2");
					if(resp32 == resp33)
						printf("\nUma embalagem preferida pela maioria: 3");
					if(resp32 == resp34)
						printf("\nUma embalagem preferida pela maioria: 4");
				}
			}else{
				if(resp33 >= resp34)
				{
					printf("\nUma embalagem preferida pela maioria: 3");
					if(resp33 == resp34)
						printf("\nUma embalagem preferida pela maioria: 4");
				}else{
					printf("\nUma embalagem preferida pela maioria: 4");
				}
			}
		}
	}else
		printf("Nao foram entrevistados voluntarios");
}
