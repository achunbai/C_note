/*
2041：【例5.9】新矩阵

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 55576     通过数: 26778
【题目描述】
已知一个n×n(2≤n≤20)
的矩阵（方阵），把矩阵二条对角线上的元素值加上10
，然后输出这个新矩阵。

【输入】
第一行为n
;

下面为一个n×n
，矩阵中各正整数小于100
。

【输出】
输出新的矩阵。共n
行，每行n
数，各数之间用一个空格隔开。

【输入样例】
5
13 66 53 89 55
11 72 61 62 46
90 10 38 10 55
95 20 43 27 19
60 12 66 16 96
【输出样例】
23 66 53 89 65 
11 82 61 72 46 
90 10 48 10 55 
95 30 43 37 19 
70 12 66 16 106
*/
#include<stdio.h>

int main()
{
	int arr[20][20], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (i == j || i == n - j - 1)
			{
				arr[i][j] += 10;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
// 课上C++代码
#include<iostream>
using namespace std;
const int N = 1e4 + 10;
int a[N][N];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	//模拟左上角到右下角的对角线
	int x1 = 1, y1 = 1;
	while (x1<=n&&y1<=n) a[x1++][y1++] += 10;
	//模拟右上角到左下角的对角线
	int x2 = 1, y2 = n;
	while (x2 <= n && y2 >= 1) a[x2++][y2--] += 10;

	//如果n是奇数，那么两条对角线一定会交于一点，按照题目要求，交点只处理一次
	if (n % 2 == 1) a[n/2+1][n/2+1] -= 10;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}cout << endl;
	}
	return 0;
}
*/ 