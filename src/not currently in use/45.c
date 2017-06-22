#include <stdio.h>
#include <stdlib.h> //for atof()
#include <ctype.h>
#include <math.h>

#define MAXOP 100 	//max size of operator or operand
#define NUMBER '0'	//signal that a number was found
#define SIN '1'
#define POW '2'
#define EXP '3'

#define MAXVAL 100	//maximum depth of val stack
#define BUFSIZE 100

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
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
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

        if(c == 's'){
            if((c = getch()) == 'i')
                if((c = getch()) == 'n')
                    return SIN;
                else
                    ungetch(c);
            else
                ungetch(c);
        }

        if(c == 'p'){
            if((c = getch()) == 'o')
                if((c = getch()) == 'w')
                    return POW;
                else
                    ungetch(c);
            else
                ungetch(c);
        }

        if(c == 'e'){
            if((c = getch()) == 'x')
                if((c = getch()) == 'p')
                    return EXP;
                else
                    ungetch(c);
            else
                ungetch(c);
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
    double op2;
    char s[MAXOP];

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
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
