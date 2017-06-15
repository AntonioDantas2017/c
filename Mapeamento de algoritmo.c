/*
AA 3.4 Mapeamento de Algoritmo
Antonio Josivaldo Dantas Filho
Ufscar - RA 580961 - G7 - Sistemas de Informação
*/

/*
listar o(s) melhor(es) aluno(s) de uma turma de alunos, dadas
as notas de tres provas (sabendo-se que todas possuem o mesmo peso
no calculo da media) e tendo-se o numero total de alunos
*/

#include <stdio.h>
#include <stdlib.h>

#define maximoAlunos 150

int main(int argc, char *argv[])
{
	int i, numeroAlunos;
	float notaProva1, notaProva2, notaProva3, melhorMedia;
	char nomeAluno[255][maximoAlunos];
	float media[maximoAlunos];

	//obtencao do numero de alunos
	printf("Digite o numero de alunos:");
	scanf("%d",&numeroAlunos);

	if(numeroAlunos > maximoAlunos)
	{
		printf("\nNumero maximo de alunos e %d\n", maximoAlunos);
	}else{ 
		//obtencao dos dados, calculo das medias e selecao da melhor
		melhorMedia = -1; //forca substituicao 
	}

	//Recebe dados dos alunos
	for(i=0;i<=numeroAlunos-1;i++)
	{
		fflush(stdin); 
		printf("\nDigite o nome do aluno %d:",i+1);
		scanf("%[^\n]",&nomeAluno[i][0]);
		printf("Digite a nota 1 do aluno %d:",i+1);
		scanf("%f",&notaProva1);
		printf("Digite a nota 2 do aluno %d:",i+1);
		scanf("%f",&notaProva2);
		printf("Digite a nota 3 do aluno %d:",i+1);
		scanf("%f",&notaProva3);
		media[i] = (notaProva1 + notaProva2 + notaProva3)/3;
		
		if(media[i]>melhorMedia)
			melhorMedia = media[i];
	} 

	//apresentacao dos resultados
	printf("\nMelhor nota final: %f\n", melhorMedia);
	for(i=0;i<numeroAlunos-1;i++)
	{
		if(media[i]==melhorMedia)
			printf("\nNome do Aluno: %s\n", nomeAluno[i]);
	}
}
