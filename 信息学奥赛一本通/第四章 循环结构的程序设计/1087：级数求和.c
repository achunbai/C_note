/*
1087：级数求和

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 106695     通过数: 48554
【题目描述】
已知：Sn=1＋12＋13＋…＋1n
。显然对于任意一个整数k
，当n
足够大的时候，Sn
大于k
。现给出一个整数k（1<=k<=15）
，要求计算出一个最小的n
，使得Sn＞k
。

【输入】
一个整数k
。

【输出】
一个整数n
。

【输入样例】
1
【输出样例】
2 
*/
#include <stdio.h>

// while循环版本
//int main()
//{
//	int k, n = 0;
//	scanf("%d", &k);
//	double sum = 0;
//	while (sum <= k)
//	{
//		sum += 1.0 / ++n;
//	}
//	printf("%d", n);
//	return 0;
//}

// do-while循环版本
//int main()
//{
//	int k, n = 0;
//	scanf("%d", &k);
//	double sum = 0;
//	do
//	{
//		sum += 1.0 / ++n;
//	}while (sum <= k);
//	printf("%d", n);
//	return 0;
//}

// for循环版本
int main()
{
	int k, n = 0;
	scanf("%d", &k);
	double sum = 0;
	for ( ; sum <= k ; )
	{
		sum += 1.0 / ++n;
	}
	printf("%d", n);
	return 0;
}