/*
1113：不与最大数相同的数字之和

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 83806     通过数: 41521
【题目描述】
输出一个整数数列中不与最大数相同的数字之和。

【输入】
输入分为两行：

第一行为N(N为接下来数的个数，N <= 100)；

第二行N个整数，数与数之间以一个空格分开，每个整数的范围是-1000,000到1000,000。

【输出】
输出为N个数中除去最大数其余数字之和。

【输入样例】
3
1 2 3
【输出样例】
3
*/
#include <stdio.h>

int main()
{
	int num[100], n, max, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		if (i == 0)
		{
			max = num[0];
		}
		else if (max < num[i])
		{
			max = num[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i] == max)
		{
			continue;
		}
		else
		{
			sum += num[i];
		}
	}
	printf("%d", sum);
	return 0;
}
