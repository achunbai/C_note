/*
1088：分离整数的各个数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 78417     通过数: 57093
【题目描述】
给定一个整数n(1≤n≤100000000)
，要求从个位开始分离出它的每一位数字。从个位开始按照从低位到高位的顺序依次输出每一位数字。

【输入】
输入一个整数，整数在1
到100000000
之间。

【输出】
从个位开始按照从低位到高位的顺序依次输出每一位数字。数字之间以一个空格分开。

【输入样例】
123
【输出样例】
3 2 1
*/
#include <stdio.h>
#include <string.h>

// for循环版本
int main()
{
	char num[10];
	scanf("%s", num);
	for (int i = strlen(num) - 1; i >= 0; i--)
	{
		printf("%c ", num[i]);
	}
	return 0;
}

// while循环版本
//int main()
//{
//	char num[10];
//	scanf("%s", num);
//	int i = strlen(num);
//	while (i > 0)
//	{
//		printf("%c ", num[--i]);
//	}
//	return 0;
//}

// do-while循环版本
//int main()
//{
//	char num[10];
//	scanf("%s", num);
//	int i = strlen(num);
//	do
//	{
//		printf("%c ", num[--i]);
//	} while (i > 0);
//	return 0;
//}