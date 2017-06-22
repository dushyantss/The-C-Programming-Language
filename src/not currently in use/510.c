#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

//push: push f onto value stack
void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

//pop: pop and return top value from stack
double pop(void){
	if(sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}


int main(int argc, char *argv[]){
	double op2;
	while(--argc > 0){
		switch(*(++argv)[0]){
			case '+':
				push(pop() + pop());
				break;
			case '*':		//should never be used as * is used to list all files
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			default:
				push(atof(*argv));
				printf("%f\n", atof(*argv));
				//printf("error: unknown command %s\n", s);
				break;
		}
	}
	printf("\t%.8g\n", pop());
	return 0;
}