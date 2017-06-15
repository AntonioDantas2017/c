/*
AA 5.4: Procedimento e Função
Antonio Josivaldo Dantas Filho
Ufscar - RA 580961 - G7 - Sistemas de Informação
*/

/*
Na linguagem C não existe função e procedimento e sim métodos
para distinguir um método ele pode ou não retornar valor. Esses
devem ser um bloco distinto do programa de execução que recebe
ou não parâmetros para executar determinadas linhas nesse bloco.
*/

/*Para os procedimentos deve-se usar a palavra 'void' para assinar
e parênteses pora receber os parâmetros e chaves para delimitar
o bloco de execução*/

//Criando Procedimento
void nomeFuncao(int parametro1, char parametro2, float parametro3)
{
	//execução
}

//Chamando Procedimento
nomeFuncao(parametro1,parametro2,parametro3);

/*Para funções deve-se seguir o mesmo molde com substituição da 
palavra 'void' pelo tipo de variável que ela retornará*/

//Criando Função do Tipo Inteiro
int nomeFuncao(int parametro1, char parametro2, float parametro3)
{
	//execução
	return 0;//Retorno de valor
}

//Chamando Função
int valor = nomeFuncao(parametro1,parametro2,parametro3);
