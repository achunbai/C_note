/*
 * 股神：假设买入1元股票，股票的变化规律是第一天不变（0），第二天涨1元（1），第三天跌1元（-1），
 * 第四天涨1元（1），第五天涨1元（1），第六天跌1元（-1），第七天涨1元（1），第八天涨1元（1），第九天涨1元（1），第十天跌1元（-1）...求N天后的股票剩余价格
*/
#include<stdio.h> 

int main()
{
	int day, value, j = 3;
	scanf("%d", &day);
	value = day;
	for (int i = 3; j <= day; i++)
	{
		j = j + i;
		value -= 2;
	}
	printf("%d", value);
	return 0;
}