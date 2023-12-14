/*
2026：【例4.12】阶乘和

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 52094     通过数: 34758
【题目描述】
求 S=1!+2!+3!+....+n!
【输入】
输入正整数n
。

【输出】
输出s
。

【输入样例】
3
【输出样例】
9
【提示】
【数据范围】

对于所有数据：1≤n≤10
。
*/
#include <stdio.h>

int main()
{
	int n, sum = 0, tmp;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		tmp = 1;
		for (int j = 1; j <= i; j++)
		{
			tmp *= j;
		}
		sum += tmp;
	}
	printf("%d", sum);
	return 0;
}
