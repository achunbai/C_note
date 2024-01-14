/*
2037：【例5.4】约瑟夫问题

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 50508     通过数: 27647
【题目描述】
N
个人围成一圈，从第一个人开始报数，数到M
的人出圈；再由下一个人开始报数，数到M
的人出圈；…输出依次出圈的人的编号。

【输入】
输入N
和M
。

【输出】
输出一行，依次出圈的人的编号。

【输入样例】
8 5
【输出样例】
5 2 8 7 1 4 6 3
【提示】
【数据范围】

对于所有数据，2≤N,M≤1000
。
*/
#include<stdio.h>

int main()
{
	int n, m, status[1001] = { 0 }, position = 0;
	scanf("%d%d", &n, &m);
	// 每个人都要出圈，控制出圈n次
	for (int i = 0; i < n; i++)
	{
		// 报数，计算谁出圈了
		for (int j = 1; j <= m; j++)
		{
			position++;
			if (position > n)
			{
				position = 1;
			}
			if (status[position])
			{
				j--;
			}
		}
		status[position] = 1;
		printf("%d ", position);
	}
	return 0;
}

// 课上案例
/*
#include<stdio.h>

int main()
{
	int n, m, status[1001] = { 0 }, position = 1;
	scanf("%d%d", &n, &m);
	int num_out = 0, call_out = 0;
	while (num_out != n)
	{
		if (position == n + 1)
		{
			position = 1;
		}
		if (!status[position])
		{
			call_out++;
		}
		if (call_out == m)
		{
			printf("%d ", position);
			status[position] = 1;
			call_out = 0;
			num_out++;
		}
		position++;
	}
	return 0;
}
*/

// 参考（部分修改）
// https://zhuanlan.zhihu.com/p/649290280
/*
#include<stdio.h>

int main() {
	int n, m, pos = 1, vis[1000] = { 0 };
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		// 一共出圈 n 次
		for (int i = 0; i < m; i++) {

			if (++pos > n) pos = 1;
			// 当前报数到最后一个了，下一次报数是第一个人 
			if (vis[pos]) i--;
			// 如果当前人已经出圈了，跳过 
		}
		if (pos - 1)
		{
			printf("%d ", pos - 1);
		}
		else
		{
			printf("%d ", n);
		}
		vis[pos] = 1;
	}
}
*/