/*
1108：向量点积计算

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 48674     通过数: 38482
【题目描述】
在线性代数、计算几何中，向量点积是一种十分重要的运算。给定两个n
维向量a=(a1,a2,...,an)
和b=(b1,b2,...,bn)
，求点积a⋅b=a1b1+a2b2+...+anbn
。

【输入】
第一行是一个整数n(1≤n≤1000)
；

第二行包含n个整数a1,a2,...,an
；

第三行包含n个整数b1,b2,...,bn
；

相邻整数之间用单个空格隔开。每个整数的绝对值都不超过1000
。

【输出】
一个整数，即两个向量的点积结果。

【输入样例】
3
1 4 6
2 1 5
【输出样例】
36
*/
#include <stdio.h>

int main()
{
	int sum = 0, va[1000], vb[1000], n; // 数组要足够大
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &va[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vb[i]);
		sum += va[i] * vb[i];
	}
	printf("%d", sum);
	return 0;
}