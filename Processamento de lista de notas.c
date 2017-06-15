#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float geral, somasala, aux2, notasala, salas, alunos, sala, aux, alunosala, geralsalas;
	//int salas, alunos, sala, aux, alunosala;
	/*
	geral = Soma de todas as notas
	geralsalas = Soma de todas as notas de salas
	salas = Soma de todas as salas 
	alunos = Soma de todos os alunos
	
	somasala = Soma Temporaria da Sala
	alunosala = Soma Temporaria dos alunos
	
	sala = Sala com melhor media
	notasala = Nota da melhor sala
	*/
	
	geral = somasala = aux2 = notasala = salas = alunos = sala = aux = alunosala = geralsalas =  0;
	printf("Digite o numero da sala, e -1(menos um) para sair:");
	scanf("%f",&aux);
	sala = aux;
	while(aux >= 0){
		salas++;
		system("cls");
		somasala=0;
		printf("Digite a nota de um aluno:");
		scanf("%f",&aux2);
		alunosala=0;
		while(aux2>=0)
		{
			system("cls");
			geral+=aux2;
			somasala+=aux2;
			alunos++;
			alunosala++;
			printf("Digite a nota de um aluno, e -1(menos um) para sair:");
			scanf("%f",&aux2);
		}
		
		aux2 = (somasala/alunosala);
		geralsalas += aux2;
		if(aux2>notasala)
		{
			notasala = aux2;
			sala = aux;
		}
		system("cls");
		printf("Digite o numero da sala, e -1(menos um) para sair:");
		scanf("%f",&aux);	
	}
	
	if(alunos>0)
	{
		printf("Media geral: %.1f\n",(geral/alunos));
		printf("Sala com melhor media: %.0f\n",sala);
		printf("Media das salas: %.1f", (geralsalas/salas));	
	}
	
}
