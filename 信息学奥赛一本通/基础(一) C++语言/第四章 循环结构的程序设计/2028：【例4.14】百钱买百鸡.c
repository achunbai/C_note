/*
2028：【例4.14】百钱买百鸡

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 67964     通过数: 32086
【题目描述】
百钱买百鸡问题。鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？

【输入】
无

【输出】
输出各种鸡翁、鸡母、鸡雏的数量，依次由小到大，每种情况各占一行,每行三个数之间用一个空格隔开。

【输入样例】
无
【输出样例】
无
*/

#include <stdio.h>

int main()
{
	for (int cock = 0; cock <= 20; cock++)
	{
		for (int hen = 0; hen < 34; hen++)
		{
			for (int chick = 0; chick < 100; chick += 3)
			{
				if (cock * 5 + hen * 3 + chick / 3 == 100 && cock + hen + chick == 100)
				{
					printf("%d %d %d\n", cock, hen, chick);
				}
			}
		}
	}
	return 0;
}