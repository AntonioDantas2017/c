/*
AA 5.4: Procedimento e Fun��o
Antonio Josivaldo Dantas Filho
Ufscar - RA 580961 - G7 - Sistemas de Informa��o
*/

/*
Na linguagem C n�o existe fun��o e procedimento e sim m�todos
para distinguir um m�todo ele pode ou n�o retornar valor. Esses
devem ser um bloco distinto do programa de execu��o que recebe
ou n�o par�metros para executar determinadas linhas nesse bloco.
*/

/*Para os procedimentos deve-se usar a palavra 'void' para assinar
e par�nteses pora receber os par�metros e chaves para delimitar
o bloco de execu��o*/

//Criando Procedimento
void nomeFuncao(int parametro1, char parametro2, float parametro3)
{
	//execu��o
}

//Chamando Procedimento
nomeFuncao(parametro1,parametro2,parametro3);

/*Para fun��es deve-se seguir o mesmo molde com substitui��o da 
palavra 'void' pelo tipo de vari�vel que ela retornar�*/

//Criando Fun��o do Tipo Inteiro
int nomeFuncao(int parametro1, char parametro2, float parametro3)
{
	//execu��o
	return 0;//Retorno de valor
}

//Chamando Fun��o
int valor = nomeFuncao(parametro1,parametro2,parametro3);
