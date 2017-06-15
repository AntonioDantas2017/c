/*
Verificações de consistência são importantes para os algoritmos. O objetivo é verificar se datas são válidas.
Deve ser elaborado um algoritmo para ler duas datas, cada uma consistindo em dia, mês e ano, dados em formato numérico (e.g., 20, 3 e 2000 para 20/3/2000). Para cada data, deve ser informado se a data é válida ou não. A validade das datas deve ser feita conforme a verificação dos intervalos especificada acima. Para esta codificação, não podem ser usados comandos condicionais
*/

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int dia1, mes1, ano1, dia2, mes2, ano2;
	int vdata1, vdata2;
	
	vdata1 = vdata2 = 0;
	
	printf("Digite o dia da primeira data:");
	scanf("%d",&dia1);
	printf("Digite o mes da primeira data:");
	scanf("%d",&mes1);
	printf("Digite o ano da primeira data:");
	scanf("%d",&ano1);
	
	printf("Digite o dia da segunda data:");
	scanf("%d",&dia2);
	printf("Digite o mes da segunda data:");
	scanf("%d",&mes2);
	printf("Digite o ano da segunda data:");
	scanf("%d",&ano2);

	
	vdata1 = (dia1 > 0) &&
			 (mes1 < 13 && mes1 > 0) &&
			 (ano1 < 0 || ano1 > 0) && 
			 (((mes1 == 1 || mes1 == 3 || mes1 == 5 || mes1 == 7 || mes1 == 8  || mes1 == 10 || mes1 == 12) && dia1 <= 31) ||
			 ((mes1 == 4 || mes1 == 6 || mes1 == 9 || mes1 == 11) && dia1 <= 30) ||
			 (mes1 = 2 && dia1 <= 28));
	
	
	vdata2 = (dia2 > 0) &&
			 (mes2 < 13 && mes2 > 0) &&
			 (ano2 < 0 || ano2 > 0) && 
			 (((mes2 == 1 || mes2 == 3 || mes2 == 5 || mes2 == 7 || mes2 == 8  || mes2 == 10 || mes2 == 12) && dia2 <= 31) ||
			 ((mes2 == 4 || mes2 == 6 || mes2 == 9 || mes2 == 11) && dia2 <= 30) ||
			 (mes2 = 2 && dia2 <= 28));
	
	printf("Data 1: %d \nData 2: %d",vdata1,vdata2);
	
	return 0;
}
