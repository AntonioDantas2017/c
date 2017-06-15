/*
AR 2.1 Programa de inserção e relatórios de dados meteorológicos 
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define TAMANHO 3

int main(int argc, char *argv[])
{
	/* definição da Definição estrutura de dados meteorológicos*/
	typedef struct 
	{
		float temperatura; 
		float atm;
		float umidade;
	} tipoDados; 
		
	// declaração de duas variáveis do tipo estrutura
	tipoDados dados[TAMANHO];
	int i,opcao;
	float mediaTemp, mediaPressao, mediaUmidade;
		
	printf("Digite os dados:\n\n");
	for(i=0;i<TAMANHO;i++)
	{
		// entrada de dados dos meteorológicos
		printf("Digite a temperatura do ponto %d: ",(i+1));
		scanf("%f", &dados[i].temperatura);
		printf("Digite o atm do ponto %d: ",(i+1));
		scanf("%f", &dados[i].atm);
		printf("Digite a umidade do ponto %d: ",(i+1));
		scanf("%f", &dados[i].umidade);
		printf("\n");	
	}
	
	//Exibindo todos os dados
	printf("\n\nPONTO | TEMPERATURA | PESSAO | UMIDADE\n");
	for(i=0;i<TAMANHO;i++)
		printf("%d | %f | %f | %f\n",i+1,dados[i].temperatura,dados[i].atm,dados[i].umidade);
		
	opcao = 1;
	while(opcao >= 1 && opcao <= 2)
	{
		printf("\nEscolha um relatorio:\n");
		printf("1. Calcule a média de temperatura, pressao e umidade para todos os pontos de coleta.\n");
		printf("2. Calcule e mostre os dados dos pontos de coleta que possuírem uma temperatura entre [19,25], uma pressão entre [0.9 e 1.1] e uma umidade entre [10,30].\n");
		printf("3. Sair do Programa.\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				mediaTemp = mediaPressao = mediaUmidade = 0; //Zerando Variaveis
				for(i=0;i<TAMANHO;i++) 
				{ 	//Somando dados
					mediaTemp += dados[i].temperatura;
					mediaPressao += dados[i].atm;
					mediaUmidade += dados[i].umidade;
				}
				//Exibindo Resultados
				printf("\n\nMedia de Temperatura %f \n Media de Pressao %f \n Media de Umidade %f\n",mediaTemp/TAMANHO, mediaPressao/TAMANHO, mediaUmidade/TAMANHO);
				break;
			case 2:
				mediaTemp = mediaPressao = mediaUmidade = 0; //Zerando Variaveis
				printf("\n\nPONTO | TEMPERATURA | PESSAO | UMIDADE\n");
				for(i=0;i<TAMANHO;i++)
				{
					if((dados[i].temperatura >= 19 && dados[i].temperatura <=25) && (dados[i].atm >= 0.9 && dados[i].atm <= 1.1) && (dados[i].umidade >= 10 && dados[i].umidade <=30))
					{
						//Exibindo Resultados e somando
						printf("%d | %f | %f | %f\n",i+1,dados[i].temperatura,dados[i].atm,dados[i].umidade);
						mediaTemp += dados[i].temperatura;
						mediaPressao += dados[i].atm;
						mediaUmidade += dados[i].umidade;	
					}
					
				}
				//Exibindo Resultados
				printf("\n\nMedia de Temperatura %f \n Media de Pressao %f \n Media de Umidade %f\n",mediaTemp/TAMANHO, mediaPressao/TAMANHO, mediaUmidade/TAMANHO);
				break;
				break;
			case 3:
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
