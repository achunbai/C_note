/*
1031：反向输出一个三位数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 135655     通过数: 82845
【题目描述】
将一个三位数反向输出，例如输入358，反向输出853。

【输入】
一个三位数n。

【输出】
反向输出n。

【输入样例】
100
【输出样例】
001
*/
#include<stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d%d%d", a % 10, a/10%10, a / 100);
	return 0;
}