/*
1092：求出e的值

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 75171     通过数: 41353
【题目描述】
利用公式e=1+11!+12!+13!+...+1n!
 ，求e
的值，要求保留小数点后10
位。

【输入】
输入只有一行，该行包含一个整数n（2≤n≤15）
，表示计算e
时累加到1n!
。

【输出】
输出只有一行，该行包含计算出来的e的值，要求打印小数点后10
位。

【输入样例】
10
【输出样例】
2.7182818011
*/

// 其实没有必要用long long和long double
// n最大为15，不会超过int的范围，而且小数点后10位，double就够了
// 但是如果n很大，就需要用long long和long double了
/*
#include <stdio.h>

int main()
{
	long long n, tmp = 1;
	long double sum = 1;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		tmp *= i;
		sum += (long double)1 / tmp;

	}
	printf("%.10llf", sum);
	return 0;
}
*/
#include <stdio.h>
int main()
{
    int n;
    double e = 1, tmp = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        tmp *= i;
        e += 1 / tmp;
    }
    printf("%.10lf", e);
    return 0;
}