/*
1098：质因数分解

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 69953     通过数: 36114
【题目描述】
已知正整数n
是两个不同的质数的乘积，试求出较大的那个质数。

【输入】
输入只有一行，包含一个正整数 n
。

对于60%的数据，6≤n≤1000
。

对于100%的数据，6≤n≤2×10^9
。

【输出】
输出只有一行，包含一个正整数 p
，即较大的那个质数。

【输入样例】
21
【输出样例】
7
*/
#include <stdio.h>
#include <math.h>

int main()
{
	int n, flag = 1;
	scanf("%d", &n);
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
		{
			for (int j = 2; j < sqrt(i); j++)
			{
				if ((n / i) % j == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				printf("%d", n / i);
			}
		}
	}
	return 0;
}
