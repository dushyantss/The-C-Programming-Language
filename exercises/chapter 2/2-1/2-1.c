/* Write a program to determine the ranges of char, short, int, and long 
 * variables, both signed and unsigned, by printing appropriate values from 
 * standard headers and by direct computation. Harder if you compute them: 
 * determine the ranges of the various floating-point types.
 */
#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{
	unsigned char c;
	unsigned short s;
	unsigned int i;
	unsigned long l;

	/* from headers */
	printf("\n----------From Headers------------\n\n");
	printf("signed char is from %d to %d.\n", CHAR_MIN, CHAR_MAX);
	printf("unigned char is from %d to %d.\n", 0, UCHAR_MAX);
	printf("signed short is from %d to %d.\n", SHRT_MIN, SHRT_MAX);
	printf("unigned short is from %d to %d.\n", 0, USHRT_MAX);
	printf("signed int is from %d to %d.\n", INT_MIN, INT_MAX);
	printf("unigned int is from %d to %u.\n", 0, UINT_MAX);
	printf("signed long is from %ld to %ld.\n", LONG_MIN, LONG_MAX);
	printf("unigned long is from %lu to %lu.\n", 0L, ULONG_MAX);
	printf("float is from %f to %f.\n", FLT_MIN, FLT_MAX);
	printf("double is from %f to %f.\n", DBL_MIN, DBL_MAX);
	printf("\n----------Calculated------------\n\n");

	c = ~0;
	c >>= 1;
	printf("signed char is from %d to %d.\n", (signed char)(c + 1), c);
	c = ~0;
	printf("unigned char is from %d to %d.\n", 0, c);

	s = ~0;
	s >>= 1;
	printf("signed short is from %d to %d.\n", (signed short)(s + 1), s);
	s = ~0;
	printf("unigned short is from %d to %d.\n", 0, s);

	i = ~0;
	i >>= 1;
	printf("signed int is from %d to %d.\n", (signed int)(i + 1), i);
	i = ~0;
	printf("unigned int is from %d to %u.\n", 0, i);

	l = ~0;
	l >>= 1;
	printf("signed long is from %ld to %ld.\n", (signed long)(l + 1), l);
	l = ~0;
	printf("unigned long is from %lu to %lu.\n", 0L, l);

	return 0;
}
