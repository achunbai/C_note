/*
2030：【例4.16】找素数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 44759     通过数: 28406
【题目描述】
输出正整数a
到b
之间的所有素数。

【输入】
输入a,b
。

【输出】
由小到大，输出a
到b
之间的所有素数。每个数占一行。

【输入样例】
5 10
【输出样例】
5
7
【提示】
【数据范围】

对于所有数据，1≤a≤b≤20000
。
*/
#include <stdio.h>

int main()
{
	int start, end, prime[20001] = { 1, 1 };
	scanf("%d %d", &start, &end);
	for (int i = 2; i < 20001; i++)
	{
		if (!prime[i])
		{
			for (int j = i + i; j < 20001; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (int i = start; i <= end; i++)
	{
		if (!prime[i])
		{
			printf("%d\n", i);
		}
	}
	return 0;
}