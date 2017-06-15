#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int dia1, mes1, ano1, dia2, mes2, ano2, vdata;
	
	printf("Digite o dia da data de inicio:");
	scanf("%d",&dia1);
	printf("Digite o mes da data de inicio:");
	scanf("%d",&mes1);
	printf("Digite o ano da data de inicio:");
	scanf("%d",&ano1);
	printf("Digite o dia da data de termino:");
	scanf("%d",&dia2);
	printf("Digite o mes da data de termino:");
	scanf("%d",&mes2);
	printf("Digite o ano da data de termino:");
	scanf("%d",&ano2);
	
	vdata = (dia1 > 0) &&
			 (mes1 < 13 && mes1 > 0) &&
			 (ano1 < 0 || ano1 > 0) && 
			 (((mes1 == 1 || mes1 == 3 || mes1 == 5 || mes1 == 7 || mes1 == 8  || mes1 == 10 || mes1 == 12) && dia1 <= 31) ||
			 ((mes1 == 4 || mes1 == 6 || mes1 == 9 || mes1 == 11) && dia1 <= 30) ||
			 (mes1 = 2 && dia1 <= 28));
	
	if(vdata)
	{
		vdata = (dia2 > 0) &&
			 (mes2 < 13 && mes2 > 0) &&
			 (ano2 < 0 || ano2 > 0) && 
			 (((mes2 == 1 || mes2 == 3 || mes2 == 5 || mes2 == 7 || mes2 == 8  || mes2 == 10 || mes2 == 12) && dia2 <= 31) ||
			 ((mes2 == 4 || mes2 == 6 || mes2 == 9 || mes2 == 11) && dia2 <= 30) ||
			 (mes2 = 2 && dia2 <= 28));
		if(vdata)
		{
			if(mes1==2)
				mes1=28;
			else{
				if(mes1 == 4 || mes1 == 6 || mes1 == 9 || mes1 == 11)
					mes1=30;
				else
					mes1=31;
			}				
			dia1 = dia1 + mes1 + (ano1*365);
			
			if(mes2==2)
				mes2=28;
			else{
				if(mes2 == 4 || mes2 == 6 || mes2 == 9 || mes2 == 11)
					mes2=30;
				else
					mes2=31;
			}				
			dia2 = dia2 + mes2 + (ano2*365);
			
			if(dia1==dia2)
				printf("As duas datas sao iguais");
			else{
				if(dia1>dia2)
					printf("A primeira data e mais recente que a segunda");
				else
					printf("A segunda data e mais recente que a primeira");
			}
		}else
			printf("Data de inicio invalida");
	}else
		printf("Data de inicio invalida");
}
