/*
2043：【例5.11】杨辉三角形

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 38432     通过数: 25340
【题目描述】
例5.11  打印杨辉三角形的前n(2≤n≤20)
行。杨辉三角形如下图：

当n=5
时

        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
输出：

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
【输入】
输入行数n
。

【输出】
输出如题述三角形。n
行，每行各数之间用一个空格隔开。

【输入样例】
5
【输出样例】
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

/*
#include<stdio.h>

int main()
{
	int arr[21][22] = { { 0 }, { 0 , 1 } }, n;
	scanf("%d", &n);
	for (int i = 2; i < 21; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/

#include<stdio.h>

int main()
{
    int a[20][20], n; // 定义一个二维数组a和一个整数n

    scanf("%d", &n); // 从标准输入读取一个整数n

    // 使用两层循环来计算杨辉三角形的每一项
    for (int i = 0; i < n; i++)
    {
        a[i][0] = a[i][i] = 1; // 杨辉三角形的每一行的第一项和最后一项都是1

        // 计算杨辉三角形的其他项
        for (int j = 1; j < i; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1]; // 杨辉三角形的每一项等于它上面的项和左上角的项的和
        }
    }

    // 使用两层循环来打印杨辉三角形
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", a[i][j]); // 打印杨辉三角形的每一项
        }
        printf("\n"); // 每打印完一行，就打印一个换行符
    }
    return 0;
}

/*
// 课上C++代码
#include<iostream>
using namespace std;
const int N = 1e2 + 10;
int a[N][N];
int main() {
	int n; cin >> n;
	a[1][1] = a[2][1] = a[2][2] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) a[i][j] = 1;
			else a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << a[i][j] << " ";
		}cout << endl;
	}
	return 0;
}
*/