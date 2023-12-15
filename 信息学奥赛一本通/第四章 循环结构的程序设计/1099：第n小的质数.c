/*
1099：第n小的质数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 70894     通过数: 34797
【题目描述】
输入一个正整数n，求第n小的质数。

【输入】
一个不超过10000的正整数n。

【输出】
第n小的质数。

【输入样例】
10
【输出样例】
29
*/
// 死循环硬算
// 1. 利用sqrt()函数，求出n以内的所有质数，然后输出第n个质数
/*
#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2;  ; i++)
	{
		int flag = 1;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			n--;
			if (!n)
			{
				printf("%d", i);
				return 0;
			}
		}
	}
	return 0;
}
*/

// 2. 利用数组，先把n以内的所有质数存起来，然后输出第n个质数（厄拉多塞筛选法）
#include <stdio.h>

int main()
{
	int n, prime[105000] = { 1, 1 }, cnt = 0;
	scanf("%d", &n);
	for (int i = 2; i < 105000; i++)
	{
		if (!prime[i])
		{
			for (int j = i + i; j < 105000; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (int i = 2; cnt <= n; i++)
	{
		if (!prime[i])
		{
			cnt++;
		}
		if (cnt == n)
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}