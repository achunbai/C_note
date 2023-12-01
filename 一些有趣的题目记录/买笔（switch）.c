/*
13.买笔(用switch 写)
[题目描述]
期末来临了，班长小Q决定将剩余班费元钱，用于购买若千支钢笔奖励给一些学习好、表现好的同学。已知商店里有三种钢笔，它们的单价为6元、5元和4元。小Q想买尽量多的笔(鼓励尽量多的同学)，同时他又不想有剩余钱。请您编一程序，帮小Q制订出一种买笔的方案。
[输入]
一个正整数x(剩余班费)
[输出]
一行，依次为6元、5元和4元钱笔的数目，用一个空格隔开
[输入样例]
10
[输出样例]
1 0 1
*/

#include<stdio.h> 

int main()
{
	int x, pen_4 = 0, pen_5 = 0, pen_6 = 0;
	scanf("%d", &x);
	pen_4 = x / 4;
	switch (x % 4)
	{
	case 1:
		pen_4--;
		pen_5++;
		break;
	case 2:
		pen_4--;
		pen_6++;
		break;
	case 3:
		pen_4--;
		pen_5++;
		pen_6++;
		break;
	default:
		break;
	}
	printf("%d %d %d", pen_6, pen_5, pen_4);
	return 0;
}