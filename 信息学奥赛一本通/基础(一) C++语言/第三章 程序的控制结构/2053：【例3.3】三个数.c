/*
2053：【例3.3】三个数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 104471     通过数: 44213
【题目描述】
输入三个整数，按从大到小的顺序输出。

【输入】
输入三个整数

【输出】
按从大到小的顺序输出。

【输入样例】
3 2 1
【输出样例】
3 2 1
*/
#include<stdio.h>

void exchange(int* num1, int* num2)
{
	*num1 ^= *num2;
	*num2 = *num1 ^ *num2;
	*num1 ^= *num2;
}

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a < b)
	{
		exchange(&a, &b);
	}
	if (b < c)
	{
		exchange(&b, &c);
	}
	if (a < b)
	{
		exchange(&a, &b);
	}
	printf("%d %d %d", a, b, c);
	return 0;
}