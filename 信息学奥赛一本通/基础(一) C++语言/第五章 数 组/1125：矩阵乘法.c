/*
1125：矩阵乘法

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 46657     通过数: 25864
【题目描述】
计算两个矩阵的乘法。n×m阶的矩阵A乘以m×k阶的矩阵B得到的矩阵C 是n×k阶的，且C[i][j] = A[i][0]×B[0][j] + A[i][1]×B[1][j] + …… +A[i][m-1]×B[m-1][j](C[i][j]表示C矩阵中第i行第j列元素)。

【输入】
第一行为n, m, k，表示A矩阵是n行m列，B矩阵是m行k列，n, m, k均小于100。

然后先后输入A和B两个矩阵，A矩阵n行m列，B矩阵m行k列，矩阵中每个元素的绝对值不会大于1000。

【输出】
输出矩阵C，一共n行，每行k个整数，整数之间以一个空格分开。

【输入样例】
3 2 3
1 1
1 1
1 1
1 1 1
1 1 1
【输出样例】
2 2 2
2 2 2
2 2 2
*/

#include <stdio.h>

int main()
{
	int m, n, k, matrix1[100][100], matrix2[100][100], result[100][100] = { 0 };
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix1[i][j]);
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &matrix2[i][j]);
		}
	}
	// 循环遍历，实现行*列
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < k; l++)
			{
				result[i][l] += matrix1[i][j] * matrix2[j][l];
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
// 课上C++代码
#include<iostream>
using namespace std;
const int N = 1e2 + 10;
int a[N][N],b[N][N],c[N][N];
int main() {
	int n, m, k; cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			cin >> b[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int p = 1; p <= m; p++) {
				c[i][j] += a[i][p] * b[p][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << c[i][j] << " ";
		}cout << endl;
	}


	return 0;
}
*/