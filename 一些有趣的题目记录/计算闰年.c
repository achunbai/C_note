#include<stdio.h> 

int main()
{
	for (int year = 1000; year <= 2000; year+=4)
	{
		if (year %400 ==0 || year%100 != 0)
		{
			printf("%d ", year);
		}
	}
	return 0;
}