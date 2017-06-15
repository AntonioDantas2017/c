/*
AA 2.2 � Pr�tica de desenvolvimento 2
Objetivo: Manipular vetores de registros de forma adequada.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o

Estat�sticas de candidatos

Objetivo
Manipular vetores de registros de forma adequada.

Descri��o
Deve ser criada uma tabela para armazenar as notas dos candidatos de uma dada prova de admiss�o. Para cada candidato deve ser guardados seu n�mero de inscri��o (um valor inteiro) e a nota obtida (real).

Os seguintes resultados devem produzidos:

Nota m�dia da prova
nota_{média} = \frac{\sum_{i=1}^{n} nota_i}{n}
Essa m�dia corresponde � soma de todas as notas, dividindo-se o total pelo n�mero de candidatos.
Vari�ncia das notas
var = \frac{\sum_{i=1}^{n} (nota_i - nota_{média})^2}{n-1}
A vari�ncia das notas deve ser calculada pela soma das diferen�as entre cada nota e a m�dia geral, cada uma delas elevada ao quadrado. Essa soma, ao final, deve ser dividida pelo n�mero de notas menos 1.
Lista de todos os n�meros de inscri��o dos candidatos cujas notas estejam no intervalo [nota_{média} - 2\sqrt{var}, nota_{média} + 2\sqrt{var}]
Nesta listagem devem ser inclu�dos todos os candidatos para os quais o m�dulo da diferen�a entre sua nota e a m�dia seja, no m�ximo, o dobro da raiz quadrada da vari�ncia.
O tamanho da tabela pode ser definido pelo desenvolvedor. Verifica��es de consist�ncia para os dados de entrada n�o s�o necess�rias (notas no intervalo 0 a 10, por exemplo).

Notem que a vari�ncia somente pode ser calculada se houver 2 ou mais alunos. Se isso n�o ocorrer, uma mensagem adequada deve ser apresentada.

O n�mero de alunos � considerado conhecido e pode ser digitado pelo operador.
*/

#include <stdio.h>
#include <math.h>

typedef struct{
	int inscricao; //Numero de Inscricao do aluno
	float nota; //Nota do aluno
}tipoCandidato;

float mediaGeral(tipoCandidato c[], int insercoes){ //Calculo da Media de todos os alunos
	float soma = 0;
	int i;
	
	for(i=0;i<insercoes;i++){
		soma+=c[i].nota; //Soma das notas
	}
	return(soma/insercoes); //retorno da Media
}

float varianciaGeral(tipoCandidato c[], int insercoes){ //Variancia das notas dos alunos
	float soma = 0; 
	float media = mediaGeral(c,insercoes); //Media das notas
	int i;
	
	for(i=0;i<insercoes;i++){ 
		soma+=(c[i].nota - media) * (c[i].nota - media); //Soma do quadradao da diferenca da media
	}
	return(soma/(insercoes-1)); //Retorno da variancia
}

int main(int argc, char *argv[]) {
	int quantidade;
	printf("Digite a quantidade de alunos:\n\n");
	scanf("%d",&quantidade);
	
	tipoCandidato candidatos[quantidade]; //Vetor de Estrutura de dados
	
	int opcao = 6;
	int insercoes = 0;
	
	while(opcao != 5){
		switch(opcao){
			case 1: //Inser��o
				if(insercoes < quantidade) //Verifica se h� espa�o disponivel
				{
					insercoes++;
					printf("Digite o numero de inscricao:");
					scanf("%d",&candidatos[insercoes-1].inscricao);
					printf("Digite a nota:");
					scanf("%f",&candidatos[insercoes-1].nota);
				}else
					printf("Sem espacos disponiveis para insercao\n\n");				
				break;
			case 2: //Media
				if(insercoes > 0)
					printf("\nMedia: %f\n\n",mediaGeral(candidatos,insercoes));	//Chamada da fun��o
				else
					printf("Nenhum aluno\n\n");
				break;
			case 3: //Variancia
				if(insercoes > 1){
					printf("\nVariancia: %f\n\n",varianciaGeral(candidatos,insercoes)); //Chamada da funcao
				}else
					printf("Quantidade de alunos insuficiente\n\n");
				break;
			case 4: //Intervalo
				if(insercoes > 1){
					float soma = 0;
					float media = mediaGeral(candidatos,insercoes); //Chamada da funcao
					float variancia = varianciaGeral(candidatos,insercoes); //Chamada da funcao
					int i;
					for(i=0;i<insercoes;i++){
						if(candidatos[i].nota > media - (2 * sqrt(variancia)) && candidatos[i].nota < media + (2 * sqrt(variancia))) //Verifica se esta no intervalo
							printf("%d\n",candidatos[i].inscricao); //Exibe numero de inscricao
					}
					
				}else
					printf("Quantidade de alunos insuficiente\n\n");
				break;
			default:
				break;
		}
		printf("\nEscolha uma opcao:\n");
		printf(" 1 para Inserir um novo registro a tabela\n");
		printf(" 2 para Nota media da prova\n");
		printf(" 3 para Variancia das notas\n");
		printf(" 4 para Lista de todos os numeros de inscricao dos candidatos cujas notas estejam no intervalo\n");
		printf(" 5 para Terminar a execucao\n");
		scanf("%d",&opcao);
	}
	
	printf("Programa finalizado!\n\n");
	system("pause");
	return 0;
}
