#include <stdio.h>

void itoa(int n, char s[]){
    static int i = 0, x = 1;
    if(n < 0){
        s[i++] = '-';
        n = -n;
    }
    if(n/10){
        ++x;
        itoa(n/10, s);
    }
    s[i++] = n % 10 + '0';
    --x;
    if(x == 0){
        s[i] = '\0';
        i = 0;
        x = 1;
    }
}

int main(){
    char s[20];
    itoa(12345, s);
    printf("%s\n", s);
    return 0;
}
