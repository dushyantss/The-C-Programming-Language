#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max #lines to be sorted */
char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myQSort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverseFlag);
int numcmp(char *, char *);
int strcmpFolded(char *, char *);
int strcmpFoldedDictionary(char *, char *);
int strcmpDictionary(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]){
	int nlines, c;				/* number of input lines read */
	int numeric = 0, reverse = 0, folded = 0, dictionary = 0;		/* 1 if numeric sort */
	
	while(--argc > 0 && (*++argv)[0] == '-'){
		while(c = *++argv[0])
		switch(c){
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case 'f':
				folded = 1;
				break;
			case 'd':
				dictionary = 1;
				break;
			default:
				printf("Using defaults: string compare and ascending sort\n");
				break;
		}
	}
	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
		myQSort((void **) lineptr, 0, nlines - 1, 
		(int(*)(void*, void*))(numeric ? numcmp :
		folded && dictionary ? strcmpFoldedDictionary :
		folded ? strcmpFolded : dictionary ? strcmpDictionary : strcmp), reverse);
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("input too big to sort\n");
		return 1;
	}
}


#define MAXLEN 1000  /* max length of any input line */

int getline(char *, int);
char *alloc(int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';  /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* getline:  read a line into s, return length  */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */
   
char *alloc(int n)    /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)  /* it fits */
    {
        allocp += n;
        return allocp - n;  /* old p */
    }
    else    /* not enough room */
        return 0;
}

/* myQSort: sort v[left]...v[right] into increasing order */
void myQSort(void *v[], int left, int right, int (*comp)(void*,void*), int reverseFlag){
	int i, last, rev = reverseFlag ? -1 : 1;
	void swap(void *v[], int, int);
	
	if(left >= right)			/* do nothing if array contains */
		return;					/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left + 1; i <= right; ++i)
		if(((*comp)(v[i],v[left])) * rev < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	myQSort(v, left, last - 1, comp, reverseFlag);
	myQSort(v, last + 1, right, comp, reverseFlag);
}

void swap(void *v[], int i, int j){
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#include <stdlib.h>
/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2){
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	return (v1 < v2) ? -1 : (v1 > v2) ? 1 : 0;
}

#include <ctype.h>
/* compare s1 with s2 */
int strcmpFolded(char *s1, char *s2){
	while(*s1 != '\0' && *s2 != '\0' && tolower(*s1) == tolower(*s2)){
		++s1;
		++s2;
	}
	
	return *s1 - *s2;
}

int strcmpDictionary(char *s1, char *s2){
	while(!(isalnum(*s1) || *s1 == ' ' || *s1 == '\t'))
		++s1;
	while(!(isalnum(*s2) || *s1 == ' ' || *s1 == '\t'))
		++s2;
	
	while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2){
		while(!(isalnum(*++s1) || *s1 == ' ' || *s1 == '\t'))
			;
		while(!(isalnum(*++s2) || *s2 == ' ' || *s2 == '\t'))
			;
	}

	return *s1 - *s2;
}

int strcmpFoldedDictionary(char *s1, char *s2){
	while(!(isalnum(*s1) || *s1 == ' ' || *s1 == '\t'))
		++s1;
	while(!(isalnum(*s2) || *s1 == ' ' || *s1 == '\t'))
		++s2;
	
	while(*s1 != '\0' && *s2 != '\0' && tolower(*s1) == tolower(*s2)){
		while(!(isalnum(*++s1) || *s1 == ' ' || *s1 == '\t'))
			;
		while(!(isalnum(*++s2) || *s2 == ' ' || *s2 == '\t'))
			;
	}

	return *s1 - *s2;
}