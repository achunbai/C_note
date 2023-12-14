/*
1093：计算多项式的值

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 65436     通过数: 35019
【题目描述】
假定多项式的形式为xn+xn−1+…+x2+x+1
，请计算给定单精度浮点数x
和正整数n
值的情况下这个多项式的值。x
在double
范围内，n≤1000000
。多项式的值精确到小数点后两位，保证最终结果在double
范围内。

【输入】
输入仅一行，包括x
和n
，用单个空格隔开。x
在double
范围内，n≤1000000
。

【输出】
输出一个实数，即多项式的值，精确到小数点后两位。保证最终结果在double
范围内。

【输入样例】
2.0 4
【输出样例】
31.00
*/

// 利用了math.h中的pow函数
/*
#include <stdio.h>
#include <math.h>

int main()
{
    double x, sum = 0;
    int n;
    scanf("%lf%d", &x, &n);
    for (int i = 0; i <= n; i++)
    {
        sum += pow(x, i);
    }
    printf("%.2lf", sum);
    return 0;
}
*/

#include <stdio.h>

int main()
{
	int n;
	double x, sum = 1, tmp = 1;
	scanf("%lf %d", &x, &n);
	for (int i = 1; i <= n; i++)
	{
		tmp *= x;
		sum += tmp;
	}
	printf("%.2lf", sum);
	return 0;
}