/*
1126：矩阵转置

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 66653     通过数: 31171
【题目描述】
输入一个n行m列的矩阵A，输出它的转置AT。

【输入】
第一行包含两个整数n和m，表示矩阵A的行数和列数(1<=n<=100，1<=m<=100)。

接下来n行，每行m个整数，表示矩阵A的元素。相邻两个整数之间用单个空格隔开，每个元素均在1~1000之间。

【输出】
m行，每行n个整数，为矩阵A的转置。相邻两个整数之间用单个空格隔开。

【输入样例】
3 3
1 2 3
4 5 6
7 8 9
【输出样例】
1 4 7
2 5 8
3 6 9
*/

#include <stdio.h>

int main()
{
	int m, n, matrix[100][100];
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrix[j][i]);
		}
		printf("\n");
	}
	return 0;
}

/*
int main()
{
	int m, n, matrix[100][100], result[100][100];
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
			result[j][i] = matrix[i][j];
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/
