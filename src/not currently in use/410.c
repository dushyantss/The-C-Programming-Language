#include <stdio.h>
#include <stdlib.h> //for atof()
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 	//max size of operator or operand
#define NUMBER '0'	//signal that a number was found

#define MAXVAL 100	//maximum depth of val stack
#define MAXLINE 1000	//maximum length for getline
#define MAXVARSTACK 15	//maximum size of the variable stack

int sp = 0;			//next free stack position
double val[MAXVAL];	//value stack
char line[MAXLINE];	//line to put the input from getline
int linep = 0;		//line index

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

/* getline:  get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

//getop: get next operator or numeric operand
int getop(char s[]){
    int i, c;
    i = 0;
    while((s[0] = c = line[linep++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(c == '-' && !isdigit(s[++i] = c = line[linep++])){
        --linep;
        s[1] = '\0';
        c = '-';
    }
    if(!isdigit(c) && c != '.'){
        if(isalpha(c)){
            for(i = 1; isalpha(s[i] = line[linep++]); ++i)
                ;
            --linep;
            s[i] = '\0';
        }
        return c;				//not a number
    }

    if(isdigit(c))				//collect integer part
        while(isdigit(s[++i] = c = line[linep++]))
            ;
    if(c == '.')				//collect fractional part
        while(isdigit(s[++i] = c = line[linep++]))
            ;
        s[i] = '\0';
        if(c != EOF)
            --linep;
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

	while(getline(line, MAXLINE)){
		linep = 0;
		while((type = getop(s))){
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
    }
    return 0;
}
