/*
1114：白细胞计数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 88315     通过数: 31411
【题目描述】
医院采样了某临床病例治疗期间的白细胞数量样本n
份，用于分析某种新抗生素对该病例的治疗效果。为了降低分析误差，要先从这n
份样本中去除一个数值最大的样本和一个数值最小的样本，然后将剩余n−2
个有效样本的平均值作为分析指标。同时，为了观察该抗生素的疗效是否稳定，还要给出该平均值的误差，即所有有效样本（即不包括已扣除的两个样本）与该平均值之差的绝对值的最大值。

现在请你编写程序，根据提供的n
个样本值，计算出该病例的平均白细胞数量和对应的误差。

【输入】
输入的第一行是一个正整数n（2<n≤300）
，表明共有n
个样本。

以下共有n
行，每行为一个浮点数，为对应的白细胞数量，其单位为109/L
。数与数之间以一个空格分开。

【输出】
输出为两个浮点数，中间以一个空格分开。分别为平均白细胞数量和对应的误差，单位也是109/L
。计算结果需保留到小数点后2
位。

【输入样例】
5
12.0
13.0
11.0
9.0
10.0
【输出样例】
11.00 1.00
*/

// 注意是排除一个最大值和一个最小值，可能存在数组中有多个最大值和最小值的情况
// 所以不能存储最大值和最小值的值，而是存储最大值和最小值的下标
#include <stdio.h>
#include <math.h>

int main()
{
	double sample[300], avg_f, sum = 0, dif = 0;
	int n, max_index = 0, min_index = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &sample[i]);
		if (sample[max_index] < sample[i])
		{
			max_index = i;
		}
		if (sample[min_index] > sample[i])
		{
			min_index = i;
		}
		sum += sample[i];
	}
	avg_f = (sum - sample[max_index] - sample[min_index]) / (n - 2);
	for (int i = 0; i < n; i++)
	{
		if ((dif < fabs(sample[i] - avg_f)) && (i != max_index) && (i != min_index))
		{
			dif = fabs(sample[i] - avg_f);
		}
	}
	printf("%.2lf %.2lf", avg_f, dif);
	return 0;
}