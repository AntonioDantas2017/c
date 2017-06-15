/*
AA 2.3 Programa de inserção e relatórios de funcionários usando registros
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[])
{
	/* definição da Definição estrutura de funcionários*/
	typedef struct 
	{
		int codFunc; // código do funcionário
		char sexoFunc; // sexo do funcionário, M (masculino) e F (feminino)
		char nome[255]; //Nome do funcionário
		char time[11]; //Time de Futebol que o funcionário torce
	} tipoFuncionario; // atenção ao uso do ponto-e-vírgula

	// declaração de duas variáveis do tipo estrutura
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
		// entrada de dados dos funcionário
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
		printf("1. Listagem dos dados de todos os funcionários.\n");
		printf("2. Listagem dos dados de todos os funcionários do sexo masculino.\n");
		printf("3. Listagem dos dados de todos os funcionários do sexo feminino.\n");
		printf("4. Contagem, por time de futebol, da quantidade de torcedores.\n"); 
		printf("5. Listagem dos dados de um funcionário fornecido o seu código.\n");
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

	// finalização do programa principal
	printf("\nSistema Finalizado\n");
	system("PAUSE");
	return 0;
}
