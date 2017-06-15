/*
AA 3.1 – Prática de desenvolvimento 1
Objetivo: O objetivo é trabalhar com vetores alocados dinamicamente, fazendo manipulações. 
Os conceitos de alocação e liberação de memória serão explorados.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação	

Manipulação de vetores

Objetivos
O objetivo é trabalhar com vetores alocados dinamicamente, fazendo manipulações. Os conceitos de alocação e liberação de memória serão explorados.

Informações gerais
Vetores, em álgebra linear, são representados por suas coordenadas.

Assim, por exemplo:

Em \mathbb{R}^2, temos \vec{v} = (v_1, v_2);
Em \mathbb{R}^3, temos \vec{w} = (w_1, w_2, w_3);
Em \mathbb{R}^6, temos \vec{u} = (u_1, u_2, u_3, u_4, u_5, u_6).
Algumas operações podem ser feitas, mas apenas se os vetores possuirem as mesmas dimensões:

Soma: \vec{v} + \vec{w} = (v_1, v_2, v_3) + (w_1, w_2, w_3) = (v_1 +w_1,v_2+ w_2, v_3+w_3);
Subtração: \vec{v} - \vec{w} = (v_1, v_2, v_3) - (w_1, w_2, w_3) = (v_1 -w_1,v_2- w_2, v_3-w_3);
Para qualquer dimensão, a soma corresponde ao vetor cujas coordenadas sejam as somas das coordenadas correspondentes.
A operação de normalização pode ser feita em qualquer vetor:

Se \vec{v} = (v_1, v_2), então sua normalização é \^v = (\frac{v_1}{||\vec{v}||}, \frac{v_2}{||\vec{v}||}), sendo ||\vec{v}|| = \sqrt{v_1^2 + v_2^2};
Se \vec{v} = (v_1, v_2, v_3, v_4), então sua normalização é \^v = (\frac{v_1}{||\vec{v}||}, \frac{v_2}{||\vec{v}||}, \frac{v_3}{||\vec{v}||}, \frac{v_4}{||\vec{v}||}), sendo ||\vec{v}|| = \sqrt{v_1^2 + v_2^2 + v_3^2 + v_4^2};
Para qualquer dimensão, basta dividir cada coordenada pela raiz quadrada da soma dos quadrados das coordenadas.
Especificação
Escreva um programa em C para ler dois vetores e dar, como resultado, nesta ordem:

A soma dos dois vetores
O vetor correspondente ao primeiro vetor normalizado
O vetor correspondente ao segundo vetor normalizado
Os vetores originais
Para a leitura, deve ser lida a dimensão do vetor e de suas coordenadas. Se a dimensão informada for inválida (menor ou igual a zero), então a dimensão deve ser zero, o que indica um vetor inválido. Como a dimensão de cada vetor pode ser qualquer uma, o espaço para as coordenadas deve ser alocado dinamicamente.

A soma deve ser feita por uma função, a qual retorna o vetor resultante correspondente à soma (dimensão e coordenadas).

A normalização deve ser feita por uma função, a qual retorna a versão normalizada do vetor.

Erros de alocação dinâmica devem ser verificados e tratados.

A leitura e a escrita dos vetores devem ser feitas por um procedimento específico para isso.
*/

#include <stdio.h>
#include <math.h>

typedef struct{ //Estrutura de um vetor
	float *vetor; //Ponteiro vetor
	int dimensao; //Dimensão do vetor
}pontV; //Tipo pontV

pontV somaVetores(pontV v1, pontV v2){ //Soma de dois vetores
	pontV r; //Auxiliar
	r.dimensao = 0;
	
	if(v1.dimensao == v2.dimensao){ //Verifica mesma dimensão
		
		int i; 
		
		r.vetor = malloc(v1.dimensao * sizeof(float *)); //Alocação do Auxiliar
		r.dimensao = v1.dimensao; //Dimensao do parametro
		
		for(i=0;i<v1.dimensao;i++) 
			r.vetor[i] = v1.vetor[i] + v2.vetor[i]; //Soma dos vetores
		
	}
	return r; //Retorna Auxiliar
}

pontV normalizarVetor(pontV v1){ //Normalização do Vetor
	pontV r; //Auxiliar
	int i;
	
	r.vetor = malloc(v1.dimensao * sizeof(float *)); //Alocação do Auxiliar
	r.dimensao = v1.dimensao; //Dimensão do Parâmetro
	
	float modulo = 0; //Modulo do vetor
	for(i=0;i<v1.dimensao;i++)
		modulo += (v1.vetor[i]) * (v1.vetor[i]); //Soma dos Quadrados do Vetor
	modulo = sqrt(modulo); //Calculo do Módulo
	
	for(i=0;i<v1.dimensao;i++)
		r.vetor[i] = v1.vetor[i]/modulo; //Normalizando o vetor
		
	return r; //Retorna Auxiliar
}

void imprimirVetor(pontV v1){ //Impressão de Vetore
	int i; 
	for(i=0;i<v1.dimensao;i++){
		printf("%f",v1.vetor[i]); //Imprimindo Vetor
		if(i+1<v1.dimensao)
			printf(","); 
	}
	printf("\n\n");
}

int main(int argc, char *argv[]) {
    
    int dimensao; //Dimensão dos Vetores
    pontV v1, v2; //2 Vetores
    
    printf("Digite a dimensao do primeiro vetor:");
    scanf("%d",&dimensao); //Recebe do Teclado
    dimensao = dimensao<0?0:dimensao; //Validando Dimensão
    v1.vetor = malloc(dimensao * sizeof(float *)); //Alocando
    v1.dimensao = dimensao; //Atribuindo
	
	printf("Digite a dimensao do segundo vetor:");
	scanf("%d",&dimensao);//Recebe do Teclado
    dimensao = dimensao<0?0:dimensao; //Validando Dimensão
	v2.vetor = malloc(dimensao * sizeof(float *)); //Alocando
	v2.dimensao = dimensao; //Atribuindo
    
	if(v1.dimensao > 0 && v2.dimensao > 0) //Verificando dimensão
    {
    	int i=0;
    	for(;i<v1.dimensao;i++){
    		printf("Digite o valor da posicao %d do primeiro vetor:", i+1);
    		scanf("%f",&v1.vetor[i]);//Recebe do Teclado
    	}
		
		for(i=0;i<v2.dimensao;i++){
			printf("Digite o valor da posicao %d do segundo vetor:", i+1);
    		scanf("%f",&v2.vetor[i]);//Recebe do Teclado
    	}	
		
		pontV aux; //Auxiliar
		aux.vetor = malloc(dimensao * sizeof(float *)); //Alocação
		aux.dimensao = dimensao; 
		
		{//Soma dos Vetores
			aux = somaVetores(v1,v2); //Chamada da função
			if(aux.dimensao >0){
				printf("\n\nA soma dos vetores e: \n");
				imprimirVetor(aux);	//Chamada do Procedimento
			}else
				printf("\nDimensao(oes) invalida!");
				
		}
		
		{//Primeiro Normalizado
			if(aux.dimensao >0){
				printf("Primeiro Vetor Normalizado: \n");
				aux = normalizarVetor(v1); //Chamada da função
				imprimirVetor(aux);	//Chamada do Procedimento
			}else
				printf("\nDimensao(oes) invalida!");
		}
		
		{//Segundo Normalizad
			if(aux.dimensao >0){
				printf("Segundo Vetor Normalizado: \n");
				aux = normalizarVetor(v2); //Chamada da função
				imprimirVetor(aux);	//Chamada do Procedimento
			}else
				printf("\nDimensao(oes) invalida!");
		}
		
		{//Vetores Originais
			if(aux.dimensao >0){
				printf("Vetores Originais: \n");
				imprimirVetor(v1); //Chamada do Procedimento	
				imprimirVetor(v2); //Chamada do Procedimento	
			}else
				printf("\nDimensao(oes) invalida!\n");
		}
		
		free(v1.vetor); //Limpar da Memória
		free(v2.vetor); //Limpar da Memória
		free(aux.vetor); //Limpar da Memória
    }	                    
    
	//Fim do Programa
	printf("Programa finalizado!");
	system("pause");
	return 0;
}

