/*
1122：计算鞍点

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 55242     通过数: 31699
【题目描述】
给定一个5×5
的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。

例如：在下面的例子中（第4
行第1
列的元素就是鞍点，值为8
 ）。

11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25
【输入】
输入包含一个5
行5
列的矩阵。

【输出】
如果存在鞍点，输出鞍点所在的行、列及其值，如果不存在，输出"not found"。

【输入样例】
11 3 5 6 9
12 4 7 8 10
10 5 6 9 11
8 6 4 7 2
15 10 11 20 25
【输出样例】
4 1 8
*/
#include <stdio.h>

int main()
{
	// 行最大 --> 遍历行，存最大的列号
	// 列最小 --> 遍历列，存最小的行号
	int matrix[6][6], saddlePoint = 0, maxCol, minRow;
	// 输入矩阵
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 1; i < 6; i++)
	{
		// 假定每次都是该行中第一列最大
		maxCol = 1;
		// 如有更大，则记录列号
		for (int j = 1; j < 6; j++)
		{
			if (matrix[i][j] > matrix[i][maxCol])
			{
				maxCol = j;
			}
		}
		// 假定每次都是该列中第一行最小
		minRow = 1;
		// 如有更小，记录行号
		for (int j = 1; j < 6; j++)
		{
			if (matrix[j][maxCol] < matrix[minRow][maxCol])
			{
				minRow = j;
			}
		}
		// 若列最小就在该行，则输出，鞍点标志位置1
		if (i == minRow)
		{
			printf("%d %d %d", minRow, maxCol, matrix[minRow][maxCol]);
			saddlePoint = 1;
		}
	}
	if (!saddlePoint)
	{
		printf("not found");
	}
}