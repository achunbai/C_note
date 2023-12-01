#include<stdio.h>
int main()
{
	int a, b, c;
  	scanf("%d%d", &a, &b);
  	c = ((a - b) >> 31) & 1;
	printf("%d", a -(a - b)* c);
	return 0;
}