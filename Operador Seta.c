/*
AA 5.2 Operador Seta
Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o
*/

/*
O operador seta axilia no acesso a informa��o por meio de um ponteiro
assim o modo tradicional (*ponteiro).valor substitui por simplismente
ponteiro->valor
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* defini��o da estrutura de funcion�rios com os campos codFunc, idadeFunc, sexoFunc e salFunc. */
	struct funcionario
	{
		int codFunc; // c�digo do funcion�rio
		int idadeFunc; // idade do funcion�rio
		char sexoFunc; // sexo do funcion�rio, M (masculino) e F (feminino)
		float salFunc; // sal�rio do funcion�rio
	}; // aten��o ao uso do ponto-e-v�rgula

	// declara��o de vari�veis
	struct funcionario funcionario1; // vari�vel do tipo estrutura
	struct funcionario funcionario2; // vari�vel do tipo estrutura
	struct funcionario *pontFunc; // ponteiro para vari�vel do tipo estrutura

	printf("A seguir, entre com todos os dados do funcionario.\n\n");
	printf("Digite o codigo: ");
	scanf("%d", &funcionario1.codFunc); // note o uso do operador &
	printf("Digite a idade: ");
	scanf("%d", &funcionario1.idadeFunc); // note o uso do operador &
	printf("Digite o sexo [F ou M]: ");
	scanf("%*c%c", &funcionario1.sexoFunc); // note o uso do operador &
	printf("Digite o salario (R$): ");
	scanf("%f", &funcionario1.salFunc); // note o uso do operador &
	printf("\n");
	
	// sa�da de dados do funcionario 1 para a tela (monitor de v�deo)
	printf("Os dados do funcionario 1 sao:\n\n");
	printf("Codigo: %d\n", funcionario1.codFunc);
	printf("Idade: %d\n", funcionario1.idadeFunc);
	printf("Sexo: %c\n", funcionario1.sexoFunc);
	printf("Salario (R$): %.2f\n", funcionario1.salFunc);
	printf("\n");

	// uso de ponteiro para estrutura
	pontFunc = &funcionario1; //Apontando para estrutura

	// uso do operador seta para a manipula��o de campos
	funcionario2.codFunc = 99; 
	funcionario2.idadeFunc = pontFunc->idadeFunc; //Usando seta para utilizar o valor em uma estrutura
	funcionario2.sexoFunc = pontFunc->sexoFunc; //Usando seta para utilizar o valor em uma estrutura
	funcionario2.salFunc = pontFunc->salFunc * 1.5; //Usando seta para utilizar o valor em uma estrutura

	// sa�da de dados do funcionario 2 para a tela (monitor de v�deo)
	printf("Os dados do funcionario 2 sao:\n\n");
	printf("Codigo: %d\n", funcionario2.codFunc);
	printf("Idade: %d\n", funcionario2.idadeFunc);
	printf("Sexo: %c\n", funcionario2.sexoFunc);
	printf("Salario (R$): %.2f\n", funcionario2.salFunc);
	printf("\n");

	// altera��o do conte�do de alguns campos de funcion�rio 1 usando ponteiro
	pontFunc->codFunc = 79; // (*pontFunc).codFunc = 79; //Usando seta para atribuir o valor em uma estrutura
	pontFunc->idadeFunc = 25; // (*pontFunc).idadeFunc = 25; //Usando seta para atribuir o valor em uma estrutura

	// sa�da de dados do funcionario 1 para a tela (monitor de v�deo)
	printf("Os dados do funcionario 1 sao:\n\n");
	printf("Codigo: %d\n", funcionario1.codFunc);
	printf("Idade: %d\n", funcionario1.idadeFunc);
	printf("Sexo: %c\n", funcionario1.sexoFunc);
	printf("Salario (R$): %.2f\n", funcionario1.salFunc);
	printf("\n");

	// finaliza��o do programa principal
	system("PAUSE");
	return 0;
}
