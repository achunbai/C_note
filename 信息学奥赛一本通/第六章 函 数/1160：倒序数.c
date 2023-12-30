/*
1160：倒序数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 48406     通过数: 33501
【题目描述】
输入一个非负整数，输出这个数的倒序数。例如输入123，输出321。

【输入】
输入一个非负整数(保证个位不为零）。

【输出】
输出倒序的数。

【输入样例】
123
【输出样例】
321
*/
/*
// 如果不用递归，则直接以字符形式读入整数，然后逆序输出即可
#include <stdio.h>
#include <string.h>

int main()
{
	char str[1001];
	fgets(str, 1001, stdin);
	int len = strlen(str) - 2;
	for (int i = len; i >= 0 ; i--)
	{
		printf("%c", str[i]);
	}
	return 0;
}
*/
/*
#include <stdio.h>

int main()
{
	char str[1001], *end = str;
	fgets(str, 1001, stdin);
	while (*end != '\0' && *end != '\n')
	{
		end++;
	}
	end--;
	while ( end >= str)
	{
		printf("%c", *end);
		end--;
	}
	return 0;
}
*/


