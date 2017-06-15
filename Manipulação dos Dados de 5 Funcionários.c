/*
AA 2.3 Programa de inser��o e relat�rios de funcion�rios usando registros
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[])
{
	/* defini��o da Defini��o estrutura de funcion�rios*/
	typedef struct 
	{
		int codFunc; // c�digo do funcion�rio
		char sexoFunc; // sexo do funcion�rio, M (masculino) e F (feminino)
		char nome[255]; //Nome do funcion�rio
		char time[11]; //Time de Futebol que o funcion�rio torce
	} tipoFuncionario; // aten��o ao uso do ponto-e-v�rgula

	// declara��o de duas vari�veis do tipo estrutura
	tipoFuncionario funcionario[5];
	int i;
	int opcao, times[5], codigoBusca;

	for(i=0;i<5;i++)
	{
		funcionario[i].codFunc = 0;
		funcionario[i].sexoFunc = ' ';
	}



	printf("Digite os dados para os 5 funcionarios:\n\n");
	for(i=0;i<5;i++)
	{
		// entrada de dados dos funcion�rio
		printf("Digite o codigo do funcionario %d: ",(i+1));
		scanf("%d", &funcionario[i].codFunc);
		printf("Digite o sexo [F ou M] do funcionario %d: ",(i+1));
		scanf("%*c%c", &funcionario[i].sexoFunc);
		printf("Digite o nome do funcionario %d: ",(i+1));
		scanf("%s", &funcionario[i].nome[0]);
		printf("Digite o time de futebol que do funcionario %d(Palmeiras, SP, Santos, Corinthians e Outros): ",(i+1));
		scanf("%s", &funcionario[i].time[0]);
		printf("\n");
	}

	opcao = 1;
	while(opcao >= 1 && opcao <= 5)
	{
		printf("Escolha um relatorio:");
		printf("1. Listagem dos dados de todos os funcion�rios.\n");
		printf("2. Listagem dos dados de todos os funcion�rios do sexo masculino.\n");
		printf("3. Listagem dos dados de todos os funcion�rios do sexo feminino.\n");
		printf("4. Contagem, por time de futebol, da quantidade de torcedores.\n"); 
		printf("5. Listagem dos dados de um funcion�rio fornecido o seu c�digo.\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				printf("\nCODIGO | SEXO | NOME DO FUNCIONARIO | TIME DE FUTEBOL\n");
				for(i=0;i<5;i++)
					printf("%d | %c | %s | %s\n",funcionario[i].codFunc,funcionario[i].sexoFunc,funcionario[i].nome,funcionario[i].time);
				break;
			case 2:
				printf("\nCODIGO | SEXO | NOME DO FUNCIONARIO | TIME DE FUTEBOL\n");
				for(i=0;i<5;i++)
				{
					if(funcionario[i].sexoFunc == 'M')
						printf("%d | %c | %s | %s\n",funcionario[i].codFunc,funcionario[i].sexoFunc,funcionario[i].nome,funcionario[i].time);
				}
				break;
			case 3:
				printf("\nCODIGO | SEXO | NOME DO FUNCIONARIO | TIME DE FUTEBOL\n");
				for(i=0;i<5;i++)
				{
					if(funcionario[i].sexoFunc == 'F')
						printf("%d | %c | %s | %s\n",funcionario[i].codFunc,funcionario[i].sexoFunc,funcionario[i].nome,funcionario[i].time);
				}
				break;
			case 4:
				times[0] = times[1] = times[2] = times[3] = times[4] = 0;
				for(i=0;i<5;i++)
				{
					if(strcmp(funcionario[i].time, "Palmeiras") == 0) 
						times[0]++;
					else{
						if(strcmp(funcionario[i].time, "SP") == 0) 
							times[1]++;
						else{
							if(strcmp(funcionario[i].time, "Santos") == 0) 
								times[2]++;
							else{
								if(strcmp(funcionario[i].time, "Corinthians") == 0) 
									times[3]++;
								else{
									if(strcmp(funcionario[i].time, "Outros") == 0) 
										times[4]++;
								}
							}
						}
					}
				}
				printf("Palmeiras: %d\n",times[0]);
				printf("SP: %d\n",times[1]);
				printf("Santos: %d\n",times[2]);
				printf("Corinthians: %d\n",times[3]);
				printf("Outros: %d\n",times[4]);
				break;
			case 5:
				codigoBusca = 0;
				printf("Digite o codigo a ser procura:\n");
				scanf("%d",&codigoBusca);
				for(i=0;i<5;i++)
				{
					if(funcionario[i].codFunc == codigoBusca)
					{
						printf("\nCODIGO | SEXO | NOME DO FUNCIONARIO | TIME DE FUTEBOL\n");
						printf("%d | %c | %s | %s\n",funcionario[i].codFunc,funcionario[i].sexoFunc,funcionario[i].nome,funcionario[i].time);
					}
				}
				break;
			default:
				break;
		}
	}

	// finaliza��o do programa principal
	printf("\nSistema Finalizado\n");
	system("PAUSE");
	return 0;
}
