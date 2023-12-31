/*
1104：计算书费

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 74093     通过数: 53516
【题目描述】
下面是一个图书的单价表：

计算概论 28.9元/本

数据结构与算法 32.7元/本

数字逻辑 45.6元/本

C++程序设计教程 78元/本

人工智能 35 元/本

计算机体系结构 86.2元/本

编译原理 27.8元/本

操作系统 43元/本

计算机网络 56元/本

JAVA程序设计 65元/本

给定每种图书购买的数量，编程计算应付的总费用。

【输入】
输入一行，包含10个整数(大于等于0，小于等于100)，分别表示购买的《计算概论》、《数据结构与算法》、《数字逻辑》、《C++程序设计教程》、《人工智能》、《计算机体系结构》、《编译原理》、《操作系统》、《计算机网络》、《JAVA程序设计》的数量（以本为单位）。每两个整数用一个空格分开。

【输出】
输出一行，包含一个浮点数f，表示应付的总费用。精确到小数点后一位。

【输入样例】
1 5 8 10 5 1 1 2 3 4
【输出样例】
2140.2
*/

// 1. 不存储数量，直接计算
#include <stdio.h>

int main()
{
	double book_price[10] = { 28.9,32.7,45.6,78,35,86.2,27.8,43,56,65 }, sum = 0;
	int quantity;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &quantity);
		sum += book_price[i] * quantity;
	}
	printf("%.1lf", sum);
	return 0;
}

// 2. 存储数量，再计算
/*
#include <stdio.h>

int main()
{
	double book_price[10] = { 28.9,32.7,45.6,78,35,86.2,27.8,43,56,65 }, sum = 0;
	int quantity[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &quantity[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		sum += book_price[i] * quantity[i];
	}
	printf("%.1lf", sum);
	return 0;
}
*/