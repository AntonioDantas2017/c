/*
AA 4.1 – Prática de desenvolvimento 1
Objetivo: Obtenção de dados a partir de registros armazenados em arquivos.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação	

Arquivo de produtos

Objetivos
Obtenção de dados a partir de registros armazenados em arquivos.

Descrição
Um arquivo é constituído dos seguintes dados:

código de produto (int)
quantidade disponível (float)
valor unitário para o registro (float)
É preciso que seja desenvolvido um programa para, dado um código de produto, obter seu valor total. Esse valor é obtido somando-se o valor multiplicado pela quantidade para todos os registros que tiverem o código especificado.

Informações adicionais
O arquivo de dados, em formato binário, que deve ser processado pode ser obtido AQUI.

Os primeiros registros do arquivo são os listados abaixo. Assim é possível verificar se a leitura de dados está correta.


 código quant. valor
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
O arquivo possui, no total, 19.651 registros, sendo 4.894 códigos distintos.

O programa deve permitir digitar um código e obter o total, fazendo isso repetidamente até que o código zero seja digitado, quando o programa termina.

O arquivo passado como exemplo não será necessariamente o mesmo que será usado na avaliação, nem em tamanho, nem em quantidade. Assim, o programa não pode se adaptar às particularidades deste arquivo específico, mas ser uma solução geral.

Não é permitido ler todos os dados para a memória usando um vetor.
*/

#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    
	FILE *arquivo; //Criação variável tipo File
	
	arquivo = fopen("produtos.dat", "r+b"); //Abertura de arquivo, pasta raiz, método le itura e escrita

	if(!arquivo){ //Se arquivo inválido
		printf("Erro de abertura do arquivo\n");
		perror("> Resultado da abertura");
		printf("> Erro: %d\n", errno); //Tipo de erro
	}else{
		int codigo; 
		
		printf("Digite o codigo a ser localizado:");
		scanf("%d",&codigo); //Leitura do teclado
		
		int achou = 0; //Variável Auxiliar de Busca
		
		while(codigo > 0){ //Se código válido
			int auxiliar = 0; //Variável auxiliar de leitura
				
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
			
			if(!achou) //Condicional para não encontrado
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


