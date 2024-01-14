/*
1112：最大值和最小值的差

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 84560     通过数: 48254
【题目描述】
输出一个整数序列中最大的数和最小的数的差。

【输入】
第一行为M，表示整数个数，整数个数不会大于10000；

第二行为M个整数，以空格隔开，每个整数的绝对值不会大于10000。

【输出】
输出M个数中最大值和最小值的差。

【输入样例】
5
2 5 7 4 2
【输出样例】
5
*/

// 不用数组
#include <stdio.h>

int main()
{
	int num, max, min, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (i == 0)
		{
			max = num;
			min = num;
		}
		if (max < num)
		{
			max = num;
		}
		if (min > num)
		{
			min = num;
		}
	}
	printf("%d", max - min);
	return 0;
}

// 用数组
/*
#include <stdio.h>

int main()
{
	int num[10000], max, min, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	max = num[0];
	min = num[0];
	for (int i = 1; i < n; i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
		if (min > num[i])
		{
			min = num[i];
		}
	}
	printf("%d", max - min);
	return 0;
}
*/