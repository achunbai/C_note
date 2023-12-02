/*
1038：苹果和虫子

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 212886     通过数: 61851
【题目描述】
你买了一箱n个苹果，很不幸的是买完时箱子里混进了一条虫子。虫子每x小时能吃掉一个苹果，假设虫子在吃完一个苹果之前不会吃另一个，那么经过y小时你还有多少个完整的苹果？

【输入】
输入仅一行，包括n，x和y（均为整数）。

【输出】
输出也仅一行，剩下的苹果个数。

【输入样例】
10 4 9
【输出样例】
7
*/
#include<stdio.h>
#include<math.h>

int main()
{
	int apple, speed, hour;
	scanf("%d%d%d", &apple, &speed, &hour);
	apple -= ceil(hour * 1.0 / speed);
	if (apple < 0)
	{
		apple = 0;
	}
	printf("%d", apple);
	return 0;
}