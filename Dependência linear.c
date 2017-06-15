/*
AA 1.1 – Prática de desenvolvimento 1
Objetivo: Dada uma matriz de valores reais, determinar se existem quaisquer duas
linhas que sejam dependentes linearmente. Cada linha determina uma sequência.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informação

Dependência linear

Introdução
No contexto desse exercício, considera-se a dependência linear entre duas sequências valores numéricos reais como a possibilidade de, a partir da primeira, se chegar à segunda, multiplicando-se cada elemento da primeira por um valor constante.

Exemplo:

Sequência 1: (2; 6; -2; 0; 10; 9)

Sequência 2: (1; 3; -1; 0; 5; 4,5)

As sequências são linearmente dependentes, pois a sequência 2 é a sequência 1 multiplicada por 0,5.

Objetivo
Dada uma matriz de valores reais, determinar se existem quaisquer duas linhas que sejam dependentes linearmente. Cada linha determina uma sequência.

O programa
Um programa deve ser escrito na linguagem C para ler uma matriz de dimensões MxN (M e N fornecidos pelo usuário).

Após a leitura, todos os valores iguais a zero devem ser substituídos pelo valor 1. Esta etapa tem como única utilidade eliminar valores nulos e evitar divisões por zero. Ela não tem função nenhuma para o programa nem para a determinação de linearidade; apenas é uma simplificação das verificações necessárias. Alternativamente, podem ser usadas matrizes sem valores nulos.

A matriz "corrigida" deve ser apresentada, juntamente com uma mensagem que indica se há ou não duas linhas dessa matriz que sejam linearmente dependentes. Não é preciso identificar quais são essas linhas.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, j, k, m, n, linear; 
  float aux_c;
  
  //Recebendo tamanho da matriz
  printf("Digite a Quantidade de Linhas:");
  scanf("%d", &m);
  printf("Digite a Quantidade de Colunas:");
  scanf("%d", &n);
    
  //Declarando a matriz
  float matriz[m][n];
  
  for(i=0;i<m;i++){
   for(j=0;j<n;j++){
    //Recebendo dados do teclado
    printf("Digite o Valor para a Linha %d e Coluna %d:",i+1, j+1);
    scanf("%f",&matriz[i][j]);
    //"Corrigindo" valores para evitar erros no programa
    if(matriz[i][j] == 0)
     matriz[i][j]  = 1;
   }
  }


  for(i=0;i<m;i++){
   linear = 0;
   for(k=i+1;k<m;k++){
    //Verificando fator multiplicador do primeiro valor
    aux_c = matriz[i][0] / matriz[k][0];                
    for(j=1;j<n;j++){
     //Verificando se fator multiplicador é linear e diferente de 1 para evitar erros no programa
     if(matriz[i][j] / matriz[k][j] == aux_c || (matriz[k][j] == 1 && matriz[i][j] == 1))
      linear = 1; //Verificado
     else{
      linear = 0; //Não linear
      j = n; //Finalizando linha
     }       
    }
   }
   if(linear) //Verificando se a linha inteira é linear
    i=m;
  }
  
  if(linear) //Exibindo Resultado
   printf("\nHa duas linhas que sao linearmente dependentes\n"); 
  else
   printf("\nNao ha duas linhas que sao linearmente dependentes\n");
   
  // finalização do programa principal
  printf("\nSistema Finalizado\n");
  system("PAUSE");
  return 0;
}
