/*
2021：【例4.6】最大公约数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 59816     通过数: 38722
【题目描述】
求两个正整数m
，n
的最大公约数。

【输入】
输入m
，n
。

【输出】
m
，n
的最大公约数。

【输入样例】
4 6
【输出样例】
2
【提示】
【数据范围】

对于全部数据：m,n<4000000
。
*/
/*
#include <stdio.h>

// 暴力解法，从最小的数开始逐个往下找，直到找到最大公约数
int main()
{
	int a, b, gcd = 1;
	scanf("%d %d", &a, &b);
	for (int i = (a < b ? a : b); i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcd = i;
			printf("%d", gcd);
			return 0;
		}
	}
	printf("%d", gcd);
	return 0;
}
*/

// 辗转相除法：
// 两个正整数a和b（a>b），他们的最大公约数等于a除以b的余数c和b之间的最大公约数
// 例如10和25，25除以10商2余5，那么10和25的最大公约数，等同于10和5的最大公约数
// 5除以10商0余5，那么5和10的最大公约数，等同于5和0的最大公约数，也就是5
// 于是得出结论：两个正整数a和b（a>b），他们的最大公约数等于a除以b的余数c和b之间的最大公约数
// 于是得出递归公式：gcd(a,b) = gcd(b,a%b)
// 于是得出递归边界：gcd(a,0) = a
// 于是得出代码：

#include <stdio.h>

int gcd(int a, int b)   // 递归公式
{
    return b == 0 ? a : gcd(b, a % b);  // 递归边界
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}

/*
#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    while (b != 0)  // 辗转相除法
    {
        c = a % b;
        a = b;
        b = c;
    }
    printf("%d", a);
    return 0;
}
*/
