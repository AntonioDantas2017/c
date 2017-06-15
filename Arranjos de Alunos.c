/*
AA 3.5 Programa de Estruturas e Relatorios de uma classe 
Antonio Josivaldo Dantas Filho
Ufscar - RA 580961 - G7 - Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//Declaracao Global
#define MAXIMO 40 //Tamanho maximo de alunos

int main(int argc, char *argv[])
{
	//Definindo Estruturas
	typedef struct{
		float nota1, nota2, nota3, media;
	}tipoProvas;
	
	typedef struct{
		char cidadeReside[255], endereco[255], telefone[16];
	}tipoContato;
	
	typedef struct{
		int ra;
		char nome[255], time[255], cidadeNascimento[255], sexo; 
		tipoProvas provas;
		tipoContato contato;
	}tipoAluno;
	
	// declaração variáveis 
	int tamanho, i, contador, contador2, opcao;	
	float mediaGeral;
	
	{
		//Recebendo tamanho do vetor
		printf("Favor digite a quantidade do arranjo entre 1 e %d alunos:", MAXIMO);
		scanf("%d",&tamanho);
	} while (tamanho < 1 || tamanho > MAXIMO);
	
	// declaração do arranjo unidimensional
	tipoAluno alunos[tamanho];	
	
	//Inserção dos dados
	for(i=0;i<tamanho;i++)
	{
		printf("\n");
		printf("Favor digite o nome do aluno %d:",i+1);
		fflush(stdin);
		scanf("%[^\n]", &alunos[i].nome[0]);
		printf("Favor digite o RA do aluno %d:",i+1);
		scanf("%d", &alunos[i].ra);
		printf("Favor digite o Time que torce do aluno %d:",i+1);
		fflush(stdin);
		scanf("%[^\n]", &alunos[i].time[0]);
		printf("Favor digite o sexo [F ou M] do aluno %d:",i+1);
		scanf("%*c%c", &alunos[i].sexo);
		printf("Favor digite a nota da prova 1 do aluno %d:",i+1);
		scanf("%f", &alunos[i].provas.nota1);
		printf("Favor digite a nota da prova 2 do aluno %d:",i+1);
		scanf("%f", &alunos[i].provas.nota2);
		printf("Favor digite a nota da prova 3 do aluno %d:",i+1);
		scanf("%f", &alunos[i].provas.nota3);
		alunos[i].provas.media = (alunos[i].provas.nota1 + alunos[i].provas.nota2 + alunos[i].provas.nota3)/3;
		printf("Favor digite a cidade que reside o aluno %d:",i+1);
		fflush(stdin);
		scanf("%[^\n]", &alunos[i].contato.cidadeReside[0]);
		printf("Favor digite o endereco do aluno %d:",i+1);
		fflush(stdin);
		scanf("%[^\n]", &alunos[i].contato.endereco[0]);
		printf("Favor digite o telefone modelo (000) 00000 0000 do aluno %d:",i+1);
		fflush(stdin);
		scanf("%[^\n]", &alunos[i].contato.telefone[0]);
		printf("Favor digite a cidade de nascimento do aluno %d:",i+1);
		fflush(stdin);
		scanf("%[^\n]", &alunos[i].cidadeNascimento[0]);
	}
	
	//Relatórios
	opcao = 1;
	while(opcao >= 1 && opcao <= 5)
	{
		printf("\n\nEscolha um relatorio:\n");
		printf("1. Quantos alunos residem na mesma cidade que nasceram.\n");
		printf("2. Quantos alunos são do sexo masculino e quanto alunos são do sexo feminino.\n");
		printf("3. Qual a nota média da turma.\n");
		printf("4. Quantos alunos possuem uma nota média menor ou igual a nota média da turma.\n"); 
		printf("5. Quantos alunos torcem para o time do Palmeiras, residem em Ribeirão Preto e possuem um RA entre 379409 e 389989.\n");
		scanf("%d", &opcao);
		
		//Verificando opcao selecionada
		switch(opcao)
		{
			case 1:
				contador = 0; //Contador 
				for(i=0;i<tamanho;i++)
				{
					if(strcmp(alunos[i].cidadeNascimento,alunos[i].contato.cidadeReside) == 0) 
						contador++;
				}
				printf("\nQuantidade de alunos residem na mesma cidade que nasceram: %d \n",contador);
				break;
			case 2:
				contador = 0; //Contador Masculino
				contador2 = 0; //Contador Feminino 
				for(i=0;i<tamanho;i++)
				{
					if(alunos[i].sexo == 'M')
						contador++;
					else
						contador2++;
				}
				printf("\nQuantidade alunos do sexo masculino %d e quantidade alunos são do sexo feminino %d.\n",contador, contador2);
				break;
			case 3:
				mediaGeral = 0;				
				for(i=0;i<tamanho;i++)
					mediaGeral += alunos[i].provas.media;
				printf("\nMedia da turma %f.\n",mediaGeral/tamanho);
				break;
			case 4:
				mediaGeral = 0;				
				for(i=0;i<tamanho;i++)
					mediaGeral += alunos[i].provas.media;
				mediaGeral = mediaGeral / tamanho;
				contador = 0; //Contador alunos
				for(i=0;i<tamanho;i++)
				{
					if(alunos[i].provas.media <= mediaGeral)
						contador++;
				}
				printf("\nQuantidade alunos possuem uma nota media menor ou igual a nota média da turma: %d \n",contador);
				break;
			case 5:
				contador = 0; //Contador 
				for(i=0;i<tamanho;i++)
				{
					if((strcmp(alunos[i].cidadeNascimento,"Ribeirao Preto") == 0) && (strcmp(alunos[i].time,"Palmeiras") == 0) && (alunos[i].ra >= 379409) && (alunos[i].ra <= 389989))
						contador++;
				}
				printf("\nQuantidade de alunos que torcem para o time do Palmeiras, residem em Ribeirão Preto e possuem um RA entre 379409 e 389989: %d \n",contador);
				break;
			default:
				break;
		}
	}
	
	// finalização do programa principal
	printf("\n\nSistema Finalizado\n");
	system("PAUSE");
	return 0;
}
