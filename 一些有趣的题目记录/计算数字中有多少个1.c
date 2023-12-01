#include<stdio.h> 

// n&(n-1)
int main()
{
	int num, count = 0;
	scanf("%d", &num);
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	printf("%d", count);
	return 0;
}
/*
* 右移计数
int main()
{
	int num, count = 0;
	scanf("%d", &num);
	for (int i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
*/