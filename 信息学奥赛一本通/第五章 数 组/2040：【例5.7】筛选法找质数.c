/*
2040：【例5.7】筛选法找质数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 32967     通过数: 22607
【题目描述】
用筛法求出n(2≤n≤1000)
以内的全部质数。

【输入】
输入n
。

【输出】
多行，由小到大的质数。

【输入样例】
10
【输出样例】
2
3
5
7
*/

// 厄拉多塞筛选法
#include <stdio.h>

int main()
{
	int n, prime[1001] = { 1,1 };
	scanf("%d", &n);
	for (int i = 2; i < 1001; i++)
	{
		if (!prime[i])
		{
			for (int j = i + i; j < 1001; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (!prime[i])
		{
			printf("%d\n", i);
		}
	}
	return 0;
}