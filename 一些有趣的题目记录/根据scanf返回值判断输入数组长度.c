#include<stdio.h>

int main() 
{
	int nums[100], i = 0, tmp;
	while (scanf("%d", &tmp))
	{
		nums[i] = tmp;
		i++;
	}
	printf("%d\n", i);
	for (int j = 0; j < i; j++)
	{
		printf("%d ", nums[j]);
	}
	return 0;
}