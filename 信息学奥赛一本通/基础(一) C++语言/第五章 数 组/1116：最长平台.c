/*
1116：最长平台

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 104751     通过数: 36706
【题目描述】
已知一个已经从小到大排序的数组，这个数组的一个平台（Plateau）就是连续的一串值相同的元素，并且这一串元素不能再延伸。例如，在 1，2，2，3，3，3，4，5，5，6中1，2-2，3-3-3，4，5-5，6都是平台。试编写一个程序，接收一个数组，把这个数组最长的平台找出来。在上面的例子中3-3-3就是最长的平台。

【输入】
第一行有一个整数n
，为数组元素的个数。第二行有n
个整数，整数之间以一个空格分开。

【输出】
输出最长平台的长度。

【输入样例】
10
1 2 2 3 3 3 4 5 5 6
【输出样例】
3
*/
#include <stdio.h>

int main()
{
	int num, bef, len = 1, n, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (i != 0)
		{
			if (num != bef)
			{
				len = 1;
			}
			else
			{
				len++;
			}
		}
		bef = num;
		if (max < len)
		{
			max = len;
		}
	}
	printf("%d", max);
	return 0;
}

// 用数组
/*
#include <stdio.h>

int main()
{
	int num[100000], len = 1, n, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		if (i == 0)
		{
			continue;
		}
		else if (num[i] != num[i - 1])
		{
			len = 1;
		}
		else
		{
			len++;
		}
		if (max < len)
		{
			max = len;
		}
	}
	printf("%d", max);
	return 0;
}
*/