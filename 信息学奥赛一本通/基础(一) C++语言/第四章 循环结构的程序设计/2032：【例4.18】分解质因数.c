/*
2032：【例4.18】分解质因数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 34476     通过数: 22037
【题目描述】
把一个合数分解成若干个质因数乘积的形式(即求质因数的过程)叫做分解质因数。分解质因数(也称分解素因数)只针对合数。

输入一个正整数n
，将n
分解成质因数乘积的形式。

【输入】
一个正整数n
。

【输出】
分解成质因数乘积的形式。质因数必须由小到大，见样例。

【输入样例】
36
【输出样例】
36=2*2*3*3
【提示】
【数据范围】

对于所有数据，2≤n≤20000
。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//int main()
//{
//	int num, prime[20001] = { 1,1 };
//	scanf("%d", &num);
//	for (int i = 2; i < 20000; i++)
//	{
//		for (int j = i + i; j < 20000; j += i)
//		{
//			prime[j] = 0;
//		}
//	}
//	printf("%d=", num);
//	for (int i = 2; i <= num; i++)
//	{
//		if (!prime[i] && num % i == 0)
//		{
//			printf("%d", i);
//			num /= i;
//			i--;
//			if (num != 1)
//			{
//				printf("*");
//			}
//		}
//	}
//	return 0;
//}

int main()
{
	int num, flag = 1;
	scanf("%d", &num);
	printf("%d=", num);
	for (int i = 2; i <= num; i++)
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (num % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && num % i == 0)
		{
			printf("%d", i);
			num /= i;
			i--;
			if (num != 1)
			{
				printf("*");
			}
		}
	}
	return 0;
}

