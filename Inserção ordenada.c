/*
AA 2.1 � Pr�tica de desenvolvimento 1
Objetivo: Manipular vetores de registros de forma adequada.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o

Inser��o ordenada

Objetivo
Manipular vetores de registros de forma adequada.

Descri��o
Deve ser criada uma tabela (vetor de registros) inicialmente vazia, ou seja, com zero elemento.

Cada registro deve conter informa��es sobre pessoas, incluindo nome e telefone.

Por meio de um menu de op��es, viabilizar as seguintes opera��es:

Inserir um novo registro � tabela, mantendo-a ordenada por nome;
Listar todos os registros da tabela;
Terminar a execu��o.
Deve haver verifica��o, na ocasi�o da inser��o, se h� espa�o na tabela para um novo registro. O tamanho da tabela deve ser fixo e determinado pelo desenvolvedor. O mesmo ocorre para o comprimento m�ximo do nome e do campo para o telefone.

Deve ser criado um procedimento para fazer a opera��o de inser��o, passando adequadamente os par�metros.
*/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define MAXNOME 100 //Quantidade Maxima de caracteres do Nome
#define MAXTELEFONE 15 //Quantidade Maxamima de caracteres do telefone
#define  QUANTIDADE 10 //Quantidade Registros

typedef struct{ //Estrutura de pessoa
	char nome[MAXNOME];
	char telefone[MAXTELEFONE]; 
}tipoPessoa;

void inserirRegistro(tipoPessoa *p,char nome[],char telefone[]){ //Procedimento para Inser��o
	strcpy(p->nome,nome); //Copiando Nome usando ponteiro na memoria da posicao a ser inserida
	strcpy(p->telefone,telefone); //Copiando Nome usando ponteiro na memoria da posicao a ser inserida
}

int main(int argc, char *argv[]) {
	
	tipoPessoa pessoas[QUANTIDADE]; //Veriavel tipoPessoa
	
	int opcao = 4; //Opcao padrao
	int i;
	int insercoes = 0; //Numero de pessoas cadastradas
	
	for(i=0;i<QUANTIDADE;i++){ //Limpando Vetor de Pessoas
		strcpy(pessoas[i].nome,"VAZIO");
		strcpy(pessoas[i].telefone,"VAZIO");
	}
	
	while(opcao != 3){ //Op��o de saida do programa
		switch(opcao){ 
			case 1: //Cadastrar pessoas
				if(insercoes < QUANTIDADE) //Verifica Limite
				{
					insercoes++; //Nova Pessoa
					
					char tempNome[MAXNOME]; //Veriavel temporaria para insercao
					char tempTelefone[MAXTELEFONE]; //Veriavel temporaria para insercao
					
					printf("Digite o nome da Pessoa:");
					fflush(stdin);
					scanf("%[^\n]",&tempNome[0]); //Recebe do teclado nome
					printf("Digite o telefone da Pessoa no formato (XX) XXXXX XXXX:");
					fflush(stdin);
					scanf("%[^\n]",&tempTelefone[0]); //Recebe do teclado telefone
					
					inserirRegistro(&pessoas[insercoes-1],strupr(tempNome),tempTelefone); //Chamada procedimento para inser��o
					
					if(insercoes > 1){ //Verifica quantidade para ordena��o
						for(i=1;i<QUANTIDADE;i++){
							if(strcmp(pessoas[i].nome,pessoas[i-1].nome) < 0){ //Compara��o para ordena��o
								//Troca de valores para ordena��o
								char aux[MAXNOME];
								strcpy(aux,pessoas[i].nome);
								strcpy(pessoas[i].nome,pessoas[i-1].nome);
								strcpy(pessoas[i-1].nome,aux);
								
								strcpy(aux,pessoas[i].telefone);
								strcpy(pessoas[i].telefone,pessoas[i-1].telefone);
								strcpy(pessoas[i-1].telefone,aux);
							}
						}	
					}	
				}else
					printf("Sem espacos disponiveis para insercao");				
					
				break;
			case 2: //Listagem de Pessoas
				printf("\nNOME;TELEFONE\n");
				for(i=0;i<QUANTIDADE;i++){
					if(strcmp(pessoas[i].nome,"VAZIO") != 0) //Verifica se espa�o ainda n�o foi preenchida
						printf("%s;%s\n",pessoas[i].nome,pessoas[i].telefone); //Exibe na tela
				}
				break;
			default:
				break;
		}
		printf("\nEscolha uma opcao:\n");
		printf(" 1 para Inserir um novo registro a tabela, mantendo-a ordenada por nome\n");
		printf(" 2 para Listar todos os registros da tabela\n");
		printf(" 3 para Terminar a execucao\n");
		scanf("%d",&opcao); //Leitura da opcao escolhida
	}
	
	//Fim do Programa
	printf("Programa finalizado!");
	system("pause");
	return 0;
}
