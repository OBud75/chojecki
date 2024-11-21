#include <stdio.h>

void swap(int* x, int* b);
int main(int argc, char const *argv[]){
	int a = 1;
	int b = 2;
	printf("a =%d, b = %d\n", a, b);
	printf("adresse mémoire de a : %p.\n", &a);
	swap (&a, &b);
	printf("a = %d, b = %d.\n", a, b);
	swap(&a, &b);
	printf("a = %d, b= %d. \n", a, b);
}

void swap(int* x, int* y) {
	printf("swapping\n");
	int temp = *x;
	*x = *y;
	*y = temp; 
}
