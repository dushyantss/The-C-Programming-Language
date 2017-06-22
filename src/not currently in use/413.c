#include <stdio.h>

void reverse(char s[]){
    static int i = 0, j = 0;
    register char temp;
    if(i >= j){
        i = j = 0;
        while(s[j] != '\0')
            ++j;
        --j;
    }
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        --j;
        ++i;
        if(i >=j)
            i = j = 0;
        else
            reverse(s);
}

int main(){
    char s[] = "Hello World, this is a test string";
    printf("%s\n", s);
    reverse(s);
    printf("%s\n", s);
    return 0;
}
