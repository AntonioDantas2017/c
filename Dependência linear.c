/*
AA 1.1 � Pr�tica de desenvolvimento 1
Objetivo: Dada uma matriz de valores reais, determinar se existem quaisquer duas
linhas que sejam dependentes linearmente. Cada linha determina uma sequ�ncia.

Antonio Josivaldo Dantas Filho
RA 580961 - G7 - Sistemas de Informa��o

Depend�ncia linear

Introdu��o
No contexto desse exerc�cio, considera-se a depend�ncia linear entre duas sequ�ncias valores num�ricos reais como a possibilidade de, a partir da primeira, se chegar � segunda, multiplicando-se cada elemento da primeira por um valor constante.

Exemplo:

Sequ�ncia 1: (2; 6; -2; 0; 10; 9)

Sequ�ncia 2: (1; 3; -1; 0; 5; 4,5)

As sequ�ncias s�o linearmente dependentes, pois a sequ�ncia 2 � a sequ�ncia 1 multiplicada por 0,5.

Objetivo
Dada uma matriz de valores reais, determinar se existem quaisquer duas linhas que sejam dependentes linearmente. Cada linha determina uma sequ�ncia.

O programa
Um programa deve ser escrito na linguagem C para ler uma matriz de dimens�es MxN (M e N fornecidos pelo usu�rio).

Ap�s a leitura, todos os valores iguais a zero devem ser substitu�dos pelo valor 1. Esta etapa tem como �nica utilidade eliminar valores nulos e evitar divis�es por zero. Ela n�o tem fun��o nenhuma para o programa nem para a determina��o de linearidade; apenas � uma simplifica��o das verifica��es necess�rias. Alternativamente, podem ser usadas matrizes sem valores nulos.

A matriz "corrigida" deve ser apresentada, juntamente com uma mensagem que indica se h� ou n�o duas linhas dessa matriz que sejam linearmente dependentes. N�o � preciso identificar quais s�o essas linhas.
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
     //Verificando se fator multiplicador � linear e diferente de 1 para evitar erros no programa
     if(matriz[i][j] / matriz[k][j] == aux_c || (matriz[k][j] == 1 && matriz[i][j] == 1))
      linear = 1; //Verificado
     else{
      linear = 0; //N�o linear
      j = n; //Finalizando linha
     }       
    }
   }
   if(linear) //Verificando se a linha inteira � linear
    i=m;
  }
  
  if(linear) //Exibindo Resultado
   printf("\nHa duas linhas que sao linearmente dependentes\n"); 
  else
   printf("\nNao ha duas linhas que sao linearmente dependentes\n");
   
  // finaliza��o do programa principal
  printf("\nSistema Finalizado\n");
  system("PAUSE");
  return 0;
}
