/*
1101：不定方程求解

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 40015     通过数: 31024
【题目描述】
给定正整数a，b，c
。求不定方程 ax+by=c
 关于未知数x
和y
的所有非负整数解组数。

【输入】
一行，包含三个正整数a，b，c
，两个整数之间用单个空格隔开。每个数均不大于1000
。

【输出】
一个整数，即不定方程的非负整数解组数。

【输入样例】
2 3 18
【输出样例】
4
*/
#include <stdio.h>

int main()
{
	int a, b, c, count = 0;
	scanf("%d %d %d", &a, &b, &c);
	for (int x = 0; x <= c / a; x++)
	{
		for (int y = 0; y <= c / b; y++)
		{
			if (a * x + b * y == c)
			{
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}