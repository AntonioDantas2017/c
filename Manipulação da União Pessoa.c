/*
AR 2.2 Programa de inserção e relatórios usando union
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[])
{
	//União de Pessoa
	typedef union pessoa
	{
		int RA; // RA de um estudante
		long int codFunc; // código de um funcionário
		char CPF[12]; // CPF de uma pessoa
	} tipoIdentificador;

	//Estrutura de Endereço
	typedef struct
	{
		char logradouro[255];
		int numero;
		char complemento[255];
		char bairro[255];
		char cidade[255];
		char estado[2];
		char pais[255];
		char cep[10];
	}tipoEndereco;

	//Estrutura de Pessoa
	typedef struct
	{
		tipoIdentificador identificador;
		char nome[255];
		int idade;
		tipoEndereco endereco;
	}tipoPessoa;
	
	//Declaracao de Variaveis
	tipoPessoa pessoa[3];
	int i, j, comp;
	char cidade[10];
	
	//Recebendo Identificadores
	printf("\nDigite o identificador do [Aluno - 1] RA:");
	scanf("%d",&pessoa[0].identificador.RA);
	printf("\nDigite o identificador do [Funcionario - 2] COD:");
	scanf("%d",&pessoa[1].identificador.codFunc);
	printf("\nDigite o identificador da pessoa [Comum - 3] CPF:");
	scanf("%s",&pessoa[2].identificador.CPF[0]);
	
	//Recebendo dados dos identificados
	printf("\n\nDigite os dados para os identificadores\n");
	for(i=0;i<3;i++)
	{
		printf("Digite o nome do identificador %d: ",i);
		fflush(stdin);
		fgets(pessoa[i].nome, 255, stdin);
		printf("Digite a idade do identificador %d: ",i);
		scanf("%d",&pessoa[i].idade);
		printf("Digite o logradouro do identificador %d: ",i);
		fflush(stdin);
		fgets(pessoa[i].endereco.logradouro, 255, stdin);
		printf("Digite o numero do identificador %d: ",i);
		fflush(stdin);
		scanf("%d",&pessoa[i].endereco.numero);
		printf("Digite o complemento do identificador %d: ",i);
		fflush(stdin);
		fgets(pessoa[i].endereco.complemento, 255, stdin);
		printf("Digite o bairro do identificador %d: ",i);
		fflush(stdin);
		fgets(pessoa[i].endereco.bairro, 255, stdin);
		printf("Digite o cidade do identificador %d: ",i);
		fflush(stdin);
		fgets(pessoa[i].endereco.cidade, 255, stdin);
		printf("Digite o estado [XX] do identificador %d: ",i);
		fflush(stdin);
		fgets(pessoa[i].endereco.estado, 255, stdin);
		printf("Digite o pais do identificador %d: ",i);
		fflush(stdin);
		fgets(pessoa[i].endereco.pais, 255, stdin);
		printf("Digite o cep [XX.XXX-XXX] do identificador %d: ",i);
		fflush(stdin);
		fgets(pessoa[i].endereco.cep, 255, stdin);
	}
	
	//Exibindo Resultados
	printf("\nSegue dados da(s) pessoa(s) que moram em 'Sao Carlos'\n");
	printf("\nIDENTIFICADOR , NOME , IDADE , LOGRADOURO , NUMERO , COMPLEMENTO , BAIRRO , CIDADE , ESTADO , PAIS , CEP");
	for(i=0;i<3;i++)
	{
		//Verificando Cidade 
		comp = 1;
		strcpy(cidade, "Sao Carlos");
		
		for(j=0;j<10;j++)
		{
			if(pessoa[i].endereco.cidade[j] != cidade[j])
				comp = 0;			
		}
		
		//Exibindo Resultados de acordo com identificador e confirmação da cidade
		if(comp)
		{
			if(i == 2)
				printf("\n%s , %s , %d , %s , %d , %s , %s , %s , %s , %s , %s",pessoa[i].identificador.CPF, pessoa[i].nome, pessoa[i].idade, pessoa[i].endereco.logradouro, pessoa[i].endereco.numero,pessoa[i].endereco.complemento,pessoa[i].endereco.bairro, pessoa[i].endereco.cidade, pessoa[i].endereco.estado, pessoa[i].endereco.pais,pessoa[i].endereco.cep);
			else{
				if(i==0)
					printf("\n%d , %s , %d , %s , %d , %s , %s , %s , %s , %s , %s",pessoa[i].identificador.RA, pessoa[i].nome, pessoa[i].idade, pessoa[i].endereco.logradouro, pessoa[i].endereco.numero,pessoa[i].endereco.complemento,pessoa[i].endereco.bairro, pessoa[i].endereco.cidade, pessoa[i].endereco.estado, pessoa[i].endereco.pais,pessoa[i].endereco.cep);
				else
					printf("\n%d , %s , %d , %s , %d , %s , %s , %s , %s , %s , %s",pessoa[i].identificador.codFunc, pessoa[i].nome, pessoa[i].idade, pessoa[i].endereco.logradouro, pessoa[i].endereco.numero,pessoa[i].endereco.complemento,pessoa[i].endereco.bairro, pessoa[i].endereco.cidade, pessoa[i].endereco.estado, pessoa[i].endereco.pais,pessoa[i].endereco.cep);
			}
				
		}
	}
	
	// finalização do programa principal
	printf("\nSistema Finalizado\n");
	system("PAUSE");
	return 0;
}
