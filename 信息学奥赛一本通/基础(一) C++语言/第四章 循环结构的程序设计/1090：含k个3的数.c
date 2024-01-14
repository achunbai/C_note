/*
1090：含k个3的数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 102425     通过数: 52918
【题目描述】
输入两个正整数m和k，其中1<m<100000，1<k<5 ，判断m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。 例如，输入：43833 3，满足条件，输出YES。如果输入：39331 3，尽管有3个3，但不能被19整除，也不满足条件，应输出NO。

【输入】
m 和 k 的值，中间用单个空格间隔。

【输出】
满足条件时输出 YES，不满足时输出 NO。

【输入样例】
43833 3
【输出样例】
YES
*/
#include <stdio.h>
// 除第一个版本外都不需要string.h
#include <string.h>
#include <stdlib.h>

// for循环版本，需要string.h
//int main()
//{
//	char num[8];
//	int k, cnt = 0;
//	scanf("%s %d", num, &k);
//	for (int i = 0; i < strlen(num); i++)
//	{
//		if (num[i] == '0' + 3)
//		{
//			cnt++;
//		}
//	}
//	if (cnt == k && atoi(num) % 19 == 0)
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//	return 0;
//}

// for循环版本，不需要string.h
//int main()
//{
//	char num[8];
//	int k, cnt = 0;
//	scanf("%s %d", num, &k);
//	for (int i = 0; num[i] != '\0'; i++)
//	{
//		if (num[i] == '0' + 3)
//		{
//			cnt++;
//		}
//	}
//	if (cnt == k && atoi(num) % 19 == 0)
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//	return 0;
//}

// while循环版本，不需要string.h
//int main()
//{
//	char num[8], *pnum = num;
//	int k, cnt = 0;
//	scanf("%s %d", num, &k);
//	while (*pnum != '\0')
//	{
//		if (*pnum == '0' + 3)
//		{
//			cnt++;
//		}
//		pnum++;
//	}
//	if (cnt == k && atoi(num) % 19 == 0)
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//	return 0;
//}

// do-while循环版本，不需要string.h
int main()
{
	char num[8], * pnum = num;
	int k, cnt = 0;
	scanf("%s %d", num, &k);
	do
	{
		if (*pnum == '0' + 3)
		{
			cnt++;
		}
		pnum++;
	}while (*pnum != '\0');
	if (cnt == k && atoi(num) % 19 == 0)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}
