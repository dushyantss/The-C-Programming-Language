#include <stdio.h>

#define swap(t, x, y) t temp = x;\
					x = y;\
					y = temp

int main(void){
	int x = 3, y = 2;
	printf("x = %d and y = %d\n", x, y);
	swap(int, x, y);
	printf("After swap, x = %d and y = %d\n", x, y);
	return 0;
}					