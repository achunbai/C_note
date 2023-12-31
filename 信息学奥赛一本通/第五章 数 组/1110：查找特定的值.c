/*
1110：查找特定的值

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 89807     通过数: 44248
【题目描述】
在一个序列(下标从1开始)中查找一个给定的值，输出第一次出现的位置。

【输入】
第一行包含一个正整数n，表示序列中元素个数。1 <=n<= 10000。

第二行包含n个整数，依次给出序列的每个元素，相邻两个整数之间用单个空格隔开。元素的绝对值不超过10000。

第三行包含一个整数x，为需要查找的特定值。x的绝对值不超过10000。

【输出】
若序列中存在x，输出x第一次出现的下标；否则输出-1。

【输入样例】
5
2 3 6 7 3
3
【输出样例】
2
*/
#include <stdio.h>

int main()
{
	int n, num[10000], m, pos = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
	{
		if (num[i] == m)
		{
			pos = i + 1;
			break;
		}
	}
	printf("%d", pos);
	return 0;
}