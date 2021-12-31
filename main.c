// main.c 파일
#include <stdio.h>

void input_data(int *, int *);
double average(int, int);

int main(void){
	int a, b;
	double avg;

	input_data(&a, &b);   
	avg = average(a, b); 
	printf("%d와 %d의 평균 : %.1lf\n", a, b, avg); 

	return 0;
}