/*
2023：【例4.8】数据统计

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 55973     通过数: 23167
【题目描述】
输入一些整数，求出它们的最小值、最大值和平均值（保留3位小数）。输入保证这些数都是不超过1000的整数。

【输入】
一行，若干个整数。

【输出】
一行，即，最小值、最大值和平均值（保留3位小数）。

【输入样例】
1 2 3
【输出样例】
1 3 2.000
【提示】
【数据范围】

数据个数不超过100
。
*/

#include <stdio.h>

int main()
{
	int tmp, max, min, sum = 0, cnt = 0;
	while (scanf("%d", &tmp) == 1)  // 注意判断是否为1，去掉则值无法控制
	{
		if (cnt == 0)
		{
			max = tmp;
			min = tmp;
		}
		if (max < tmp)
		{
			max = tmp;
		}
		if (min > tmp)
		{
			min = tmp;
		}
		sum += tmp;
		++cnt;
	}
	printf("%d %d %.3lf", min, max, 1.0 * sum / cnt);
	return 0;
}