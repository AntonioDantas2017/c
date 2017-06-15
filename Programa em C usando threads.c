/* 
Antonio Josivaldo Dantas Filho - 580961 - G7
SO - AA7.1: Programa em C usando threads
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define LIN 10
#define COL 10
#define N_THREADS 8
#define LEN 128

//Matrizes globais para soma e reconhecimento em todas as threads
int m1[LIN][COL];
int m2[LIN][COL];
int m3[LIN][COL];

//Estrutura argumentos do thread
typedef struct {
	int idx, fim;
}thread_arg, *ptr_thread_arg;

//Chamada da fun��o de bloqueio de threads
pthread_mutex_t _mutex_lock; 

//Fun��o para soma por linha
void *
soma(void *arg)
{
	//Vari�veis auxiliares
 	int j, k, endidx;
 	
 	//recupera argumentos
	ptr_thread_arg argument = (ptr_thread_arg)arg;
	endidx = argument->idx + argument->fim;
	
	//Realizando a soma das colunas em determinas linhas
	for(j=argument->idx; j<endidx; j++) {
		for(k=0; k < COL; k++){
			//Bloqueia a thread para uso da vari�vel global
	 		pthread_mutex_lock(&_mutex_lock); 
	 		
	 		m3[j][k]= m1[j][k] + m2[j][k]; //soma
			
			//Desbloqueia a thread
			pthread_mutex_unlock(&_mutex_lock); 
			sleep(0); //dorme nada	
		}
	}
}

int 
main (int argc, char *argv[])
{
	pthread_t thread[N_THREADS];//Multithread
	thread_arg arguments[N_THREADS];//Argumentos da thread

	//Vari�veis auxiliares
	int result, t, tamanho, restante;
	char err_msg[LEN];
	int i,j;
 	
 	srand((unsigned int)getpid()); //aleatoriedade

	//Atribui as matrizes n�meros aleat�rios
	for(i=0; i < LIN; i++)
 		for(j=0; j < COL; j++) {
 			m1[i][j]= rand() % 9;
 			m2[i][j]= rand() % 9;
 			m3[i][j]= 0; //zera matriz resultado
 		}
 	
	//Inicializa a thread desbloqueada
	pthread_mutex_init(&_mutex_lock, NULL); 
 	
	//Cria as threads identificando com a fun��o e argumentos
	tamanho = LIN / N_THREADS; //quantidade de linhas por thread
	restante = LIN % N_THREADS; //restante da divis�o
	for(t=0; t<N_THREADS; t++) {
		arguments[t].idx = t * tamanho; //in�cio indentificado
		arguments[t].fim = tamanho; //quantidade de linhas fim
		if(t == (N_THREADS - 1))
			arguments[t].fim += restante; //restante na �ltima thread

		result = pthread_create(&thread[t], NULL, soma, &(arguments[t]) );; 
		
		if (result) {
			strerror_r(result,err_msg,LEN);
			printf("Erro criando thread %d: %s\n",t,err_msg);
			exit(0);
		}
	}

	//Realiza as chamadas das threads
	for(t=0; t<N_THREADS; t++) {
		result = pthread_join(thread[t], NULL);
		if (result) {
			strerror_r(result,err_msg,LEN);
			fprintf(stderr,"Erro em pthread_join: %s\n",err_msg);
			exit(0);
		}
	}
	
	// Imprime matrizes
 	printf("\n");
 	for(i=0; i < LIN; i++) {
 		for(j=0; j < COL; j++)
 			printf("%d ", m1[i][j]);
 		printf("\t");
 		for(j=0; j < COL; j++)
 			printf("%d ",m2[i][j]);
 		printf("\t");
 		for(j=0; j < COL; j++)
 			printf("%2d ",m3[i][j]);
 		printf("\n");
 	}
 	printf("\n");

	//Encerra
	pthread_mutex_destroy(&_mutex_lock); //Finaliza bloqueios
	pthread_exit(NULL); //Finaliza as threads
	
	/*Resolu��o das perguntas:
	1 - Como fazer a soma acima em paralelo, usando v�rias threads?
	Para realizar a soma em pararelo foi divida as linhas entre v�rias threads.
	
 	2 - Quantas threads usar? Como dividir as linhas entre as threads?
 	Podem ser utilizadas qualquer quantidade de threads identificada na constante, o ideal � ser o n�mero de core(n�cleos) 
	que o processador tem, aumentando o desempenho. Para dividir foi usado o n�mero de linhas na matriz dividas entre
	a quantidade pr� definida de threads e o restante na �ltima thread.
	
 	3 - Fazendo a soma em paralelo, como saber se todos os elementos foram somados antes de imprimir, como acima?
 	A soma das colunas em linhas dividas garante a resolu��o correta do algoritmo, a fun��o principal(main) tamb�m � 
 	uma thread e para finalizar aguarda a execu��o de todas as threads.
 	
 	4 - Como sincronizar todas as threads antes da impress�o?
 	Para realizar a sincroniza��o � utilizado o m�todo mutex onde existe o bloqueio das threads para utiliza��o das 
 	vari�vel global, ap�s a finaliza��o da �ltima thread chamada, ent�o � realizada a impress�o.
 	*/
 	
	
}



