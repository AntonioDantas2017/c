/*
AA 4.1 � Pr�tica de desenvolvimento 1
Objetivo: Obten��o de dados a partir de registros armazenados em arquivos.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o	

Arquivo de produtos

Objetivos
Obten��o de dados a partir de registros armazenados em arquivos.

Descri��o
Um arquivo � constitu�do dos seguintes dados:

c�digo de produto (int)
quantidade dispon�vel (float)
valor unit�rio para o registro (float)
� preciso que seja desenvolvido um programa para, dado um c�digo de produto, obter seu valor total. Esse valor � obtido somando-se o valor multiplicado pela quantidade para todos os registros que tiverem o c�digo especificado.

Informa��es adicionais
O arquivo de dados, em formato bin�rio, que deve ser processado pode ser obtido AQUI.

Os primeiros registros do arquivo s�o os listados abaixo. Assim � poss�vel verificar se a leitura de dados est� correta.


 c�digo quant. valor
 3300 - 20.3 - 35.22
 6626 - 1.2 - 67.77
 4777 - 5.7 - 71.76
 4359 - 25.9 - 63.54
 7769 - 9.3 - 28.39
 7709 - 28.0 - 52.07
 7405 - 20.5 - 17.56
 6651 - 9.4 - 41.95
 6443 - 29.6 - 42.38
 5874 - 2.7 - 48.64
 7439 - 15.1 - 66.07
 7841 - 15.4 - 9.59
 4850 - 5.5 - 78.56
 4906 - 29.0 - 9.04
 3492 - 8.3 - 5.85
 4211 - 6.9 - 20.06
 7299 - 5.0 - 14.99
 4287 - 12.5 - 54.33
 5362 - 19.3 - 57.69
 7832 - 14.3 - 2.85
etc.
O arquivo possui, no total, 19.651 registros, sendo 4.894 c�digos distintos.

O programa deve permitir digitar um c�digo e obter o total, fazendo isso repetidamente at� que o c�digo zero seja digitado, quando o programa termina.

O arquivo passado como exemplo n�o ser� necessariamente o mesmo que ser� usado na avalia��o, nem em tamanho, nem em quantidade. Assim, o programa n�o pode se adaptar �s particularidades deste arquivo espec�fico, mas ser uma solu��o geral.

N�o � permitido ler todos os dados para a mem�ria usando um vetor.
*/

#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    
	FILE *arquivo; //Cria��o vari�vel tipo File
	
	arquivo = fopen("produtos.dat", "r+b"); //Abertura de arquivo, pasta raiz, m�todo le itura e escrita

	if(!arquivo){ //Se arquivo inv�lido
		printf("Erro de abertura do arquivo\n");
		perror("> Resultado da abertura");
		printf("> Erro: %d\n", errno); //Tipo de erro
	}else{
		int codigo; 
		
		printf("Digite o codigo a ser localizado:");
		scanf("%d",&codigo); //Leitura do teclado
		
		int achou = 0; //Vari�vel Auxiliar de Busca
		
		while(codigo > 0){ //Se c�digo v�lido
			int auxiliar = 0; //Vari�vel auxiliar de leitura
				
			while(!achou && fread(&auxiliar, sizeof(int), 1, arquivo) != 0){ //Leitura do arquivo 
				
				if(auxiliar == codigo) //Condicional para busca 
				{
					printf("\nCodigo Encontrado: %d \n",auxiliar);
					
					float quant, valor;
					
					fread(&quant, sizeof(float), 1, arquivo); //Leitura da Quantidade
					fread(&valor, sizeof(float), 1, arquivo); //Leitura do Valor
					printf("Valor Total: %.2f \n\n",quant*valor); //Exibe resultado 
					
					achou = 1; //Encontrado
				}
				
			}
			
			if(!achou) //Condicional para n�o encontrado
				printf("\n!!!!!!!!!! Codigo nao encontrado !!!!!!!!!!\n");
			
			achou = 0; 
			
			fseek(arquivo, 0, SEEK_SET); //Retorna para o inicio do arquivo para uma nova busca
			
			printf("\nDigite o codigo a ser localizado:"); //Nova busca
			scanf("%d",&codigo);	
		}
				
		
		fclose(arquivo); //Fecha arquivo
	}
    
	//Fim do Programa
	printf("Programa finalizado!");
	system("pause");
	return 0;
}


