/*
AA 1.2 � Pr�tica de desenvolvimento 1
Objetivo: Simular a travessia de um submarino por uma �rea minada, tentando n�o colidir em nenhuma mina.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o

�rea minada

Introdu��o
Este trabalho tem como objetivo simular a travessia de um submarino por uma �rea minada, tentando n�o colidir em nenhuma mina.

Para este fim, deve ser definido o campo como um quadriculado de MxN posi��es. Cada posi��o deve ser livre ou conter uma mina.

A posi��o inicial do submarino deve ser na parte de baixo, em qualquer posi��o livre. Na parte superior deve haver um ponto no qual o submarino deve estar para considerar sua travessia como terminada.

A figura ilustra a ideia do tabuleiro que simula o espa�o do oceano pelo qual o submarino deve passar.

Minas

O jogo
O programa consiste em definir um tabuleiro como o indicado na figura, marcando as �reas livres e as minadas, colocando na �ltima linha a posi��o inicial do submarino e na primeira linha um ponto de sa�da.

O tabuleiro deve ser apresentado ao jogador, por�m ocultando-se as minas.

A cada passo, deve ser solicitado ao usu�rio uma dire��o de movimento: esquerda, direita, para cima, ou para baixo. De acordo com essa dire��o, a posi��o do submarino deve ser atualizada e o tabuleiro deve ser redesenhado.

Ap�s cada movimenta��o do submarino, deve ser dada uma dica ao usu�rio, indicando quantas minas est�o na vizinhan�a. Para a vizinhan�a, devem ser consideradas as oito posi��es do quadriculado ao redor da posi��o do submarino. Com isso, o jogador consegue alguma ajuda para desviar das minas.

O jogo termina quando o submarino vai para uma posi��o onde h� uma mina (falha na miss�o) ou quando chega � posi��o de sa�da (sucesso).

O programa
Um programa em C deve ser escrito para implementar esse jogo.

Uma matriz deve ser usada para representar o tabuleiro. As dimens�es do tabuleiro podem fixas. Nessa matriz devem ser marcadas as posi��es onde existem as minas. A quantidade de minas pode ser fixa e as minas devem ser colocada aleatoriamente no tabuleiro.

A posi��o inicial do submarino pode ser aleat�ria (desde que esteja na �ltima linha) ou arbitr�ria. O mesmo ocorre para a posi��o de sa�da, apenas restrita a ser na primeira linha.

O que entregar
Deve ser entregue o c�digo fonte, escrito na linguagem C, que implementa o jogo descrito. N�o devem ser entregues outros arquivos, como execut�veis ou outros gerados pela IDE que estiver em uso.

Observa��es
Desenhar o tabuleiro pode ser algo simples, como indicar com um "X" a sa�da, com um "S" o submarino e com um "." as demais posi��es. Para atualizar o tabuleiro, basta apresent�-lo novamente.
Ao se verificar a quantidade de minas na vizinhan�a, deve-se cuidar das situa��es em que o submarino esteja nas bordas do tabuleiro.
A fun��o rand() gera n�meros aleat�rios. Como a fun��o pode ser usada para colocar as minas no tabuleiro deve ser discutido no f�rum da unidade.
Notem que os crit�rios de avalia��o incluem a qualidade do c�digo, documenta��o, uso correto das estruturas de dados, uso correto dos comandos, escolha adequada dos identificadores etc.
*/

#include <stdio.h>
#include <conio.h>

const int LINHAS = 12; //Quantidade de Linhas
const int COLUNAS = 8; //Quantidade de Colunas
const int MINAS = 7; //Quantidade de Minas
 
int funcaoRandomLinhas(){ //Retorna aleatoriamente dentro do limite de linhas um valor
	int aux = rand() % 100;
	while(aux > LINHAS)
		aux = rand() % 100;
	return aux;
}

int funcaoRandomColunas(){ //Retorna aleatoriamente dentro do limite de colunas um valor
	int aux = rand() % 100;
	while(aux > COLUNAS)
		aux = rand() % 100; 
	return aux;
}

int mudarPosicao(int *matriz[LINHAS][COLUNAS], int *posicaoL, int *posicaoC, int posicaoLN, int posicaoCN){ //Muda a posi��o do Submarino
	if((matriz[posicaoLN][posicaoCN]) == 3 || (matriz[posicaoLN][posicaoCN-1]) == 3 || (matriz[posicaoLN][posicaoCN+1]) == 3)
		return 2; //Venceu o jogo
	else{
		if((matriz[posicaoLN][posicaoCN]) == 1 || (matriz[posicaoLN][posicaoCN-1]) == 1 || (matriz[posicaoLN][posicaoCN+1]) == 1)
			return 0; //Perdeu o jogo
		else{
			(matriz[*posicaoL][*posicaoC]) = (matriz[*posicaoL][*posicaoC-1]) = (matriz[*posicaoL][*posicaoC+1]) = 0; //Posi��o antiga
			(matriz[posicaoLN][posicaoCN]) = (matriz[posicaoLN][posicaoCN-1]) = (matriz[posicaoLN][posicaoCN+1]) = 2; //Nova posi��a
			(*posicaoL) = posicaoLN; //Nova linha
			(*posicaoC) = posicaoCN; //Nova Coluna
			return 1; //Continua o jogo
		}
			
	}			
}

int main(int argc, char *argv[]) {

	int matriz[LINHAS][COLUNAS];
	
	int i, j, k;
	for(i=0;i<LINHAS;i++){
		for(j=0;j<COLUNAS;j++)
			matriz[i][j] = 0; //Limpa matriz
	}
	
 	matriz[0][funcaoRandomColunas()] = 3; //Definindo posi��o da sa�da
	
	int posicaoC = funcaoRandomColunas(); //Definindo coluna do submarino
	int posicaoL = LINHAS-1; //Definindo linha do submarino
	
	while(posicaoC < 1 || posicaoC > COLUNAS - 1)
		posicaoC = funcaoRandomColunas(); //Definindo aleat�riamente uma coluna dentro do limite 
	
	matriz[posicaoL][posicaoC] = 2; //Definindo posi��o do submarino
	matriz[posicaoL][posicaoC-1] = 2; //Definindo posi��o do submarino
	matriz[posicaoL][posicaoC+1] = 2; //Definindo posi��o do submarino
	
	int linha;
	int coluna;
	for(i=0;i<MINAS;i++){ //Definindo Minas
		linha = funcaoRandomLinhas(); 
		coluna = funcaoRandomColunas();
		if(matriz[linha][coluna] == 0) //Verificando se espa�o est� dispon�vel
			matriz[linha][coluna] = 1; //Definindo Mina
		else
			i--; //Espa�o ocupado
	}
	
	int vivo = 1; //Controle do jogo
		
	while(vivo == 1) 
	{
		for(i=0;i<LINHAS;i++){ //Imprimindo Tabuleiro
			printf("\n ");
			for(k=0;k<COLUNAS;k++)
				printf("_ ");
			
			printf("\n");
			
			for(j=0;j<COLUNAS;j++){
				if(matriz[i][j] == 0 || matriz[i][j] == 1)
				{
					printf("| ");	//Espa�o em branco
				}else{
					if(matriz[i][j] == 2)
						printf("|S"); //Submarino
					else
						printf("|X"); //Saida
				}
				//printf("|%d", matriz[i][j]); //Para ver os valores
			}
			
			printf("|"); 
		}	
		
		int contMinas = 0; 
		for(i=posicaoL-8;i<posicaoL+8;i++){	//Contando minas ao redor do submarino
			for(j=posicaoC-8;j<posicaoC+8;j++){
				if(i<LINHAS-1 && i>0 && j<COLUNAS-1 && j>0){ //Verificando Limite
					if(matriz[i][j] == 1)
						contMinas++;
				}				
			}
		}	
		
		int movimento;
		
		printf("\nDigite uma das opcoes:");
		printf("\n8 para Subir");
		printf("\n4 para Esquerda");
		printf("\n6 para Direita");
		printf("\n2 para Descer\n");
		printf("\nExiste(em) %d minas nas proximidades",contMinas);
		scanf("%d",&movimento); //Recebe do teclado o movimento
		
		switch(movimento){
			case 8: //Cima
				if(posicaoL - 1 >= 0)
					vivo = mudarPosicao(matriz,&posicaoL,&posicaoC,posicaoL-1,posicaoC);
				break;
			case 4: //Esquerda
				if(posicaoC - 1 > 0)
					vivo = mudarPosicao(matriz,&posicaoL,&posicaoC,posicaoL,posicaoC-1);
				break;
			case 6: //Direita
				if(posicaoC + 1 < COLUNAS-1)
					vivo = mudarPosicao(matriz,&posicaoL,&posicaoC,posicaoL,posicaoC+1);
				break;
			case 2: //Baixo
				if(posicaoL + 1 <= LINHAS-1)
					vivo = mudarPosicao(matriz,&posicaoL,&posicaoC,posicaoL+1,posicaoC);
				break;
			default: //Outra op��o
				printf("Opcao invalida!");
				break;
		}
	}
	
	if(vivo==2) //Verificando final do jogo
		printf("\nPARABENS VOCE VENCEU\n");
	else
		printf("\nGAME OVER\n");
			
	system("pause");
	return 0;
}
