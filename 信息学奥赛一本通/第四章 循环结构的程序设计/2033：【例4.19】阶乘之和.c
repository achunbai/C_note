/*
2033：【例4.19】阶乘之和

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 74498     通过数: 18785
【题目描述】
输入n
，计算S=1!+2!+3!+…+n!
的末6
位(不含前导0)。n≤106
， n!
表示前n
个正整数之积。

【输入】
输入n
。

【输出】
如题述，之和。

【输入样例】
10
【输出样例】
37913
【提示】
【数据范围】

对于所有数据，1≤n≤999999
。
*/
#include <stdio.h>

// 同余定理：
// (a*b)%c=((a%c)*(b%c))%c

// 利用for循环嵌套分别求出每个阶乘的末6位，然后累加
// 通过3，超时1
// 时间复杂度为O(n^2)
//int main()
//{
//	int n, sum = 0, tmp;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		tmp = 1;
//		for (int j = 1; j <= i; j++)
//		{
//			tmp = tmp * j % 1000000;
//		}
//		sum = (sum + tmp) % 1000000;
//	}
//	printf("%06d", sum);
//	return 0;
//}

// 仔细想想，其实不用每次都重新求阶乘，只需要在上一次的基础上乘以i即可
// 时间复杂度降低为O(n)，通过4
int main()
{
	int n, sum = 0, tmp = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		tmp = tmp * i % 1000000;
		sum = (sum + tmp) % 1000000;
	}
	printf("%06d", sum);
	return 0;
}