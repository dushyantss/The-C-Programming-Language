// I can implement = in 2 ways, in the first one i can make rule to allow using it
// only like =x or =y. This way would be very easy but would break the current way.
// I coult also do it where I keep a stack of variables used in a line and increment
// push in the stack if variable name is used, and pop it off when any operator other
//than = is used.
//I am going to try the second method because it is more elegent, though harder

#include <stdio.h>
#include <stdlib.h> //for atof()
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 	//max size of operator or operand
#define NUMBER '0'	//signal that a number was found

#define MAXVAL 100	//maximum depth of val stack
#define BUFSIZE 100
#define MAXVARSTACK 15	//maximum size of the variable stack

char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

void printTop(void){
    if(bufp > 0)
        printf("%c\n", buf[bufp - 1]);
    else
        printf("error: empty stack, nothing to print");
}

void swapTopTwo(void){
    char temp;
    if(bufp > 1){
        temp = buf[bufp - 1];
        buf[bufp - 1] = buf[bufp - 2];
        buf[bufp - 2] = temp;
    }else
        printf("error: stack has less than two elements, cannot swap");
}

void clearStack(void){
    bufp = 0;
}

//get a (possibly pushed back) character
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//push character back on input
void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int sp = 0;			//next free stack position
double val[MAXVAL];	//value stack

//push: push f onto value stack
void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

//pop: pop and return top value from stack
double pop(void){
    if(sp > 0){
        return val[--sp];
	}
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}
//for the variable stack
char varStack[MAXVARSTACK];
int varStackP = 0;

char popVar(void){
	if(varStackP > 0){
		return varStack[--varStackP];
	}else{
		printf("error: no variable left in varStack\n");
		return 0;
	}
}

void pushVar(char c){
	if(varStackP < MAXVARSTACK){
		varStack[varStackP++] = c;
	}else{
		printf("error: variable stack full, can't push %c\n", c);
	}
}

//getop: get next operator or numeric operand
int getop(char s[]){
    int i, c;
    i = 0;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(c == '-' && !isdigit(s[++i] = c = getch())){
        ungetch(c);
        s[1] = '\0';
        c = '-';
    }
    if(!isdigit(c) && c != '.'){
        if(isalpha(c)){
            for(i = 1; isalpha(s[i] = getch()); ++i)
                ;
            ungetch(s[i]);
            s[i] = '\0';
        }
        return c;				//not a number
    }

    if(isdigit(c))				//collect integer part
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')				//collect fractional part
        while(isdigit(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if(c != EOF)
            ungetch(c);
        return NUMBER;
}

//reverse Polish caclulator
int main(){
    int type;
    double op2, opVar;
    char s[MAXOP], var;

    double vars[26];
    for(int x = 0; x < 26; ++x)
        vars[x] = 1234567890.0987654321;

    printf("variable a will hold the last printed value\n");

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
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
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case '=':
                op2 = pop();
				opVar = pop();
				while(opVar != vars[(var = popVar()) - 'a'])
					;
				vars[var - 'a'] = op2;
				push(op2);
                break;
            case '\n':
                printf("\t%.8g\n", vars[0] = pop());
                break;
            default:
                if(strcmp(s, "sin") == 0){
                    push(sin(pop()));
                }else if(strcmp(s, "pow") == 0){
                    op2 = pop();
                    push(pow(pop(), op2));
                }else if(strcmp(s, "exp") == 0){
                    push(exp(pop()));
                }else if( isalpha(s[0]) && s[1] == '\0'){
					pushVar(s[0]);    
                   push(vars[s[0] - 'a']);
                }else{
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
    }
    return 0;
}
