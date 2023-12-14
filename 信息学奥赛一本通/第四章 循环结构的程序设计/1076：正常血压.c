/*
1076：正常血压

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 102077     通过数: 47174
【题目描述】
监护室每小时测量一次病人的血压，若收缩压在90-140之间并且舒张压在60-90之间(包含端点值)则称之为正常，现给出某病人若干次测量的血压值，计算病人保持正常血压的最长小时数。

【输入】
第一行为一个正整数n(n<100)，其后有n行，每行2个正整数，分别为一次测量的收缩压和舒张压。

【输出】
输出仅一行，血压连续正常的最长小时数。

【输入样例】
4
100 80
90 50
120 60
140 90
【输出样例】
2
*/

// 注意是最长正常血压保持小时数
// 血压在英文中被称为 “Blood Pressure”，通常缩写为 “BP”。
// 收缩压被称为 “Systolic Blood Pressure”，缩写为 “SBP”。
// 舒张压被称为 “Diastolic Blood Pressure”，缩写为 “DBP”。

#include <stdio.h>

int main()
{
	int n, SBP, DBP, hour = 0, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &SBP, &DBP);
		if ((89 < SBP && SBP < 141)&&(59 < DBP && DBP < 91))
		{
			hour++;
			if (max < hour)
			{
				max = hour;
			}
		}
		else
		{
			hour = 0;
		}
	}
	printf("%d", max);
	return 0;
}