/*
1047：判断能否被3，5，7整除

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 170505     通过数: 79497
【题目描述】
给定一个整数，判断它能否被3
，5
，7
整除，并输出以下信息：

1、能同时被3
，5
，7
整除（直接输出3 5 7，每个数中间一个空格）；

2、只能被其中两个数整除（输出两个数，小的在前，大的在后。例如：3 5或者3 7或者5 7，中间用空格分隔）；

3、只能被其中一个数整除（输出这个除数）；

4、不能被任何数整除，输出小写字符‘n’，不包括单引号。

【输入】
输入一行，包括一个整数。

【输出】
输出一行，按照描述要求给出整数被3
，5
，7
整除的情况。

【输入样例】
105
【输出样例】
3 5 7
*/
#include<stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	if (a % 105 == 0)
	{
		printf("3 5 7");
	}
	else if (a % 35 == 0)
	{
		printf("5 7");
	}
	else if (a % 21 == 0)
	{
		printf("3 7");
	}
	else if (a % 15 == 0)
	{
		printf("3 5");
	}
	else if (a % 7 == 0)
	{
		printf("7");
	}
	else if (a % 5 == 0)
	{
		printf("5");
	}
	else if (a % 3 == 0)
	{
		printf("3");
	}
	else
	{
		printf("n");
	}
	return 0;
}