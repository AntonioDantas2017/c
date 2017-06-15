/*
AA 4.2 – Prática de desenvolvimento 1
Objetivo: Acesso aos dados de um arquivo para fazer alterações.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação	

Modificação de dados

Objetivo
Acesso aos dados de um arquivo para fazer alterações.
Um arquivo é constituído dos seguintes dados:

código de produto (int)
quantidade disponível (float)
valor unitário para o registro (float)
É preciso que seja desenvolvido um programa para, dado um código de produto e um valor, alterar todos os registros que contenham o código especificado para que o campo do valor unitário seja atualizado. Os outros campos devem permanecer inalterados.

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

O programa deve permitir digitar um código apenas uma vez um código e um valor, fazendo a correção e terminando. Se houver novas alterações, o programa deve ser executado novamente.

O arquivo passado como exemplo não será necessariamente o mesmo que será usado na avaliação, nem em tamanho, nem em quantidade. Assim, o programa não pode se adaptar às particularidades deste arquivo específico, mas ser uma solução geral.

Não é permitido ler todos os dados para a memória usando um vetor.

Não é permitido criar um novo arquivo com os dados modificados. As alterações devem ser feitas no próprio arquivo.
*/

#include <stdio.h>
#include <errno.h>

typedef struct{ //Estrutura de Prodouto
	int codigo;
	float quant, valor;
}tipoProduto;

int main(int argc, char *argv[]) {
    
	FILE *arquivo; //Variável do tipo FIOLE
	tipoProduto produto; //Variável de Produto
	
	arquivo = fopen("produtos.dat", "r+b"); //Abertura do arquivo

	if(!arquivo){
		printf("Erro de abertura do arquivo\n");
		perror("> Resultado da abertura");
		printf("> Erro: %d\n", errno);
	}else{
		printf("Digite o codigo a ser localizado:");
		scanf("%d",&produto.codigo); //Leitura do teclado
		
		int achou = 0; //Auxiliar de Busca
		
		while(produto.codigo > 0){ 
			tipoProduto auxiliar; //Auxiliar de Leitura
				
			while(!feof(arquivo) && fread(&auxiliar, sizeof(tipoProduto), 1, arquivo) != 0){
				
				if(auxiliar.codigo == produto.codigo) //Verifica se encontrou
				{
					printf("Digite o valor a ser alterado:");  
					scanf("%f",&produto.valor); //Leitura do Valor
					
					printf("Codigo: %d \n",auxiliar.codigo); 
					produto.quant = auxiliar.quant; //Recebe nova quantidade
					
					fseek(arquivo, -sizeof(tipoProduto), SEEK_CUR); //Volta ao inicio do registro

					if(fwrite(&produto, sizeof(tipoProduto),1, arquivo) != 1) //Escreve no arquivo
						printf("\n\nErro na escrita!\n\n");					
					
					achou++; 
				}
				
			}
			
			if(achou == 0){ //Exibe Resultados 
				printf("Nenhum Codigo Encontrado!\n");
			}else{
				prinft("%d Codigos Alterados",achou)
			}
				
			achou = 0;
			
			fseek(arquivo, 0, SEEK_SET); //Inicia nova alteração
			
			printf("Digite o codigo a ser localizado:");		
			scanf("%d",&produto.codigo); //Leitura do teclado	
		}
				
		fclose(arquivo); //Fecha arquivo
		
	}
    
	//Fim do Programa
	printf("Programa finalizado!");
	system("pause");
	return 0;
}


