/*
1124：矩阵加法

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 57232     通过数: 37535
【题目描述】
输入两个n
行m
列的矩阵A
和B
，输出它们的和A+B
。

【输入】
第一行包含两个整数n
和m
，表示矩阵的行数和列数(1≤n≤100，1≤m≤100)
。

接下来n
行，每行m
个整数，表示矩阵A
的元素。

接下来n
行，每行m
个整数，表示矩阵B
的元素。

相邻两个整数之间用单个空格隔开，每个元素均在1∼1000
之间。

【输出】
n
行，每行m
个整数，表示矩阵加法的结果。相邻两个整数之间用单个空格隔开。

【输入样例】
3 3
1 2 3
1 2 3
1 2 3
1 2 3
4 5 6
7 8 9
【输出样例】
2 4 6
5 7 9
8 10 12
*/

#include <stdio.h>

int main()
{
	int m, n, matrix1[100][100], matrix2[100][100], count = 0;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix1[i][j]);
		}

	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix2[i][j]);
			matrix1[i][j] += matrix2[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix1[i][j]);
		}
		printf("\n");
	}
	return 0;
}