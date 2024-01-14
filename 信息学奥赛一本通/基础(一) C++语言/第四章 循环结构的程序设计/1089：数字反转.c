/*
1089：数字反转

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 104390     通过数: 55427
【题目描述】
给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零，例如输入−380
，反转后得到的新数为−83
。

【输入】
输入共 1 行，一个整数N
。

−1,000,000,000≤N≤1,000,000,000
。

【输出】
输出共 1 行，一个整数，表示反转后的新数。

【输入样例】
123
【输出样例】
321
【提示】
【输入输出样例 2】

输入：

-380
输出：

-83
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// while循环版本
//int main()
//{
//	char num[11];
//	scanf("%s", num);
//	int length = strlen(num);
//	char* start = num, * end = &num[length - 1];
//	if (num[0] == '-' || num[0] == '+')
//	{
//		start++;
//	}
//	while (start < end)
//	{
//		char tmp = *start;
//		*(start++) = *end;
//		*(end--) = tmp;
//	}
//	printf("%d", atoi(num));
//	return 0;
//}

// do-while循环版本
//int main()
//{
//	char num[11];
//	scanf("%s", num);
//	int length = strlen(num);
//	char* start = num, * end = &num[length - 1];
//	if (num[0] == '-' || num[0] == '+')
//	{
//		start++;
//	}
//	do
//	{
//		char tmp = *start;
//		*(start++) = *end;
//		*(end--) = tmp;
//	}while (start < end);
//	printf("%d", atoi(num));
//	return 0;
//}

// for循环版本
int main()
{
	char num[11];
	scanf("%s", num);
	int length = strlen(num);
	char* start = num, * end = &num[length - 1];
	if (num[0] == '-' || num[0] == '+')
	{
		start++;
	}
	for ( ; start < end; start++, end--)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
	}
	printf("%d", atoi(num));    // atoi()函数将字符串转换为整数
	return 0;
}