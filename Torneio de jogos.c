#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	int hor1, min1, hor2, min2, vhora;
	
	printf("Digite hora de inicio: ");
	scanf("%d",&hor1);
	printf("Digite minuto de inicio: ");
	scanf("%d",&min1);
	printf("Digite hora de termino: ");
	scanf("%d",&hor2);
	printf("Digite minuto de termino: ");
	scanf("%d",&min2);
	
	vhora = (hor1 >= 0) && (hor2 >= 0) &&
			(hor1 < 24) && (hor2 < 24) &&
			(min1 >= 0) && (min2 >= 0) &&
			(min2 < 60) && (min2 < 60);
		
	if(vhora)
	{
		if(hor1 == hor2)
		{
			if(min1 < min2)
				printf("0h%dmin",(min2-min1));
			else
				printf("99h99min");
		}else{
			if(hor2==0)
				hor2 = 24;
			else{
				if(hor1==23)
					hor1 = 0;
			}
			if(hor1 < hor2)
			{
				if(min1 > min2)
					printf("0h%dmin",(60-min1)+min2);
				else{
					if(hor2-hor1 == 1)
						printf("1h%dmin",min2-min1);
					else
						printf("99h99min");
				}
			}else
				printf("99h99min");
		}	
	}else
		printf("99h99min");

}
