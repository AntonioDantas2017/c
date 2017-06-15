#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float p1x, p2x, p3x, p1y, p2y, p3y, s, a, b, c;
	
	printf("Digite o ponto Ax: ");
	scanf("%f",&p1x);
	printf("Digite o ponto Ay: ");
	scanf("%f",&p1y);
	printf("Digite o ponto Bx: ");
	scanf("%f",&p2x);
	printf("Digite o ponto By: ");
	scanf("%f",&p2y);
	printf("Digite o ponto Cx: ");
	scanf("%f",&p3x);
	printf("Digite o ponto Cy: ");
	scanf("%f",&p3y);
	 
	a = sqrt(pow((p1x-p2x),2)+pow((p1y-p2y),2));
	b = sqrt(pow((p1x-p3x),2)+pow((p1y-p3y),2));
	c = sqrt(pow((p3x-p2x),2)+pow((p3y-p2y),2));
	
	s = (a+b+c)/2;
	
	printf("O valor da area e: %f", sqrt(s*(s-a)*(s-b)*(s-c)));
	
	return 0;
}
