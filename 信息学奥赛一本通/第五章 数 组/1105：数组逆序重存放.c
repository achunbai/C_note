/*
1105：数组逆序重存放

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 82037     通过数: 55878
【题目描述】
将一个数组中的值按逆序重新存放。例如，原来的顺序为8,6,5,4,1。要求改为1,4,5,6,8。

【输入】
两行：第一行数组中元素的个数n（1<n<100)
，第二行是n
个整数，每两个整数之间用空格分隔。

【输出】
一行：输出逆序后数组的整数，每两个整数之间用空格分隔。

【输入样例】
5
8 6 5 4 1
【输出样例】
1 4 5 6 8
*/

#include <stdio.h>

// 1. 顺序存放 --> 执行逆序 --> 顺序输出
//int main()
//{
//	int n, num[100];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &num[i]);
//	}
//	for (int i = 0; i < n / 2; i++)
//	{
//		int tmp = num[i];
//		num[i] = num[n - i - 1];
//		num[n - i - 1] = tmp;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", num[i]);
//	}
//	return 0;
//}

// 2. 逆序存放 --> 顺序输出
int main()
{
	int n, num[100];
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

// 3. 顺序存放 --> 逆序输出
//int main()
//{
//	int n, num[100];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &num[i]);
//	}
//	for (int i = n - 1; i >= 0; i--)
//	{
//		printf("%d ", num[i]);
//	}
//	return 0;
//}