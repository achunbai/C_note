/*
1033：计算线段长度

时间限制: 1000 ms         内存限制: 32768 KB
提交数: 93422     通过数: 52852
【题目描述】
已知线段的两个端点的坐标A(Xa,Ya)
，B(Xb，Yb)
，求线段AB
的长度，保留到小数点后3
位。

【输入】
第一行是两个实数Xa，Ya
，即A
的坐标。

第二行是两个实数Xb，Yb
，即B
的坐标。

输入中所有实数的绝对值均不超过10000
。

【输出】
一个实数，即线段AB
的长度，保留到小数点后3
位。

【输入样例】
1 1
2 2
【输出样例】
1.414
*/
#include<stdio.h>
#include<math.h>

int main()
{
	double x1, y1, x2, y2;
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	printf("%.3lf", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
	return 0;
}