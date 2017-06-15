/*
AA 2.2 Programa de definição, atribuição e exibição de variáveis em uma estrutura usando typedef
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* definição da tipo estrutura de funcionários*/
	typedef struct 
	{
		int codFunc; // código do funcionário
		int idadeFunc; // idade do funcionário
		char sexoFunc; // sexo do funcionário, M (masculino) e F (feminino)
		float salFunc; // salário do funcionário
		char nome[255]; //Nome do funcionário
		char time[255]; //Time de Futebol que o funcionário torce
	} tipoFuncionario; // atenção ao uso do ponto-e-vírgula
	
	// declaração de duas variáveis do tipo estrutura
	tipoFuncionario funcionario1;
	tipoFuncionario funcionario2;

	// entrada de dados do funcionário 1

	printf("A seguir, entre com todos os dados do funcionario.\n\n");
	printf("Digite o codigo: ");
	scanf("%d", &funcionario1.codFunc);
	printf("Digite a idade: ");
	scanf("%d", &funcionario1.idadeFunc);
	printf("Digite o sexo [F ou M]: ");
	scanf("%*c%c", &funcionario1.sexoFunc);
	printf("Digite o salario (R$): ");
	scanf("%f ", &funcionario1.salFunc);
	printf("Digite o nome do funcionario: ");
	scanf("%s", &funcionario1.nome[0]);
	printf("Digite o time de futebol que o funcionario torce: ");
	scanf("%s", &funcionario1.time[0]);
	printf("\n");
	
	// saída de dados do funcionario 1 para a tela (monitor de vídeo)
	
	printf("Os dados do funcionario 1 sao:\n\n");
	printf("Codigo: %d\n", funcionario1.codFunc);
	printf("Idade: %d\n", funcionario1.idadeFunc);
	printf("Sexo: %c\n", funcionario1.sexoFunc);
	printf("Salario (R$): %.2f\n", funcionario1.salFunc);
	printf("Nome: %s\n", funcionario1.nome);
	printf("Time de futebol: %s\n", funcionario1.time);
	printf("\n");

	// atribuição dos dados do funcionário 1 para o funcionario 2
	funcionario2 = funcionario1;

	//saída de dados do funcionario 2 para a tela (monitor de vídeo)
	printf("Os dados do funcionario 2 sao:\n\n");
	printf("Codigo: %d\n", funcionario2.codFunc);
	printf("Idade: %d\n", funcionario2.idadeFunc);
	printf("Sexo: %c\n", funcionario2.sexoFunc);
	printf("Salario (R$): %.2f\n", funcionario2.salFunc);
	printf("Nome: %s\n", funcionario2.nome);
	printf("Time de futebol: %s\n", funcionario2.time);
	printf("\n");

	// finalização do programa principal
	system("PAUSE");
	return 0;
}
