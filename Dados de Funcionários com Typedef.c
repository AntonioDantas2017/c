/*
AA 2.2 Programa de defini��o, atribui��o e exibi��o de vari�veis em uma estrutura usando typedef
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* defini��o da tipo estrutura de funcion�rios*/
	typedef struct 
	{
		int codFunc; // c�digo do funcion�rio
		int idadeFunc; // idade do funcion�rio
		char sexoFunc; // sexo do funcion�rio, M (masculino) e F (feminino)
		float salFunc; // sal�rio do funcion�rio
		char nome[255]; //Nome do funcion�rio
		char time[255]; //Time de Futebol que o funcion�rio torce
	} tipoFuncionario; // aten��o ao uso do ponto-e-v�rgula
	
	// declara��o de duas vari�veis do tipo estrutura
	tipoFuncionario funcionario1;
	tipoFuncionario funcionario2;

	// entrada de dados do funcion�rio 1

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
	
	// sa�da de dados do funcionario 1 para a tela (monitor de v�deo)
	
	printf("Os dados do funcionario 1 sao:\n\n");
	printf("Codigo: %d\n", funcionario1.codFunc);
	printf("Idade: %d\n", funcionario1.idadeFunc);
	printf("Sexo: %c\n", funcionario1.sexoFunc);
	printf("Salario (R$): %.2f\n", funcionario1.salFunc);
	printf("Nome: %s\n", funcionario1.nome);
	printf("Time de futebol: %s\n", funcionario1.time);
	printf("\n");

	// atribui��o dos dados do funcion�rio 1 para o funcionario 2
	funcionario2 = funcionario1;

	//sa�da de dados do funcionario 2 para a tela (monitor de v�deo)
	printf("Os dados do funcionario 2 sao:\n\n");
	printf("Codigo: %d\n", funcionario2.codFunc);
	printf("Idade: %d\n", funcionario2.idadeFunc);
	printf("Sexo: %c\n", funcionario2.sexoFunc);
	printf("Salario (R$): %.2f\n", funcionario2.salFunc);
	printf("Nome: %s\n", funcionario2.nome);
	printf("Time de futebol: %s\n", funcionario2.time);
	printf("\n");

	// finaliza��o do programa principal
	system("PAUSE");
	return 0;
}
