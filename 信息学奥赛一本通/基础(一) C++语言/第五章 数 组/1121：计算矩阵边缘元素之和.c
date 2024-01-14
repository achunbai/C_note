/*
1121：计算矩阵边缘元素之和

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 66973     通过数: 38371
【题目描述】
输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。

【输入】
第一行分别为矩阵的行数m
和列数n（m<100，n<100）
，两者之间以一个空格分开。

接下来输入的m
行数据中，每行包含n
个整数，整数之间以一个空格分开。

【输出】
输出对应矩阵的边缘元素和。

【输入样例】
3 3
3 4 1
3 7 1
2 0 1
【输出样例】
15
*/
#include<stdio.h>

int main()
{
	int matrix[100][100], m, n, sum = 0;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (i == 0 || i == m - 1)
		{
			for (int j = 0; j < n ; j++)
			{
				sum += matrix[i][j];
			}
		}
		else
		{
			sum += matrix[i][0] + matrix[i][n - 1];
		}
	}
	printf("%d", sum);
	return 0;
}