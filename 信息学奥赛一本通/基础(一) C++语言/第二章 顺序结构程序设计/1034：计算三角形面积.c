/*
1034：计算三角形面积

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 131999     通过数: 45097
【题目描述】
平面上有一个三角形，它的三个顶点坐标分别为(x1,y1),(x2,y2),(x3,y3)
，那么请问这个三角形的面积是多少，精确到小数点后两位。

【输入】
输入仅一行，包括6
个单精度浮点数，分别对应x1,y1,x2,y2,x3,y3
。

【输出】
输出也是一行，输出三角形的面积，精确到小数点后两位。

【输入样例】
0 0 4 0 0 3
【输出样例】
6.00
*/
#include<stdio.h>
#include<math.h>

double getLength(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
	double x1, y1, x2, y2, x3, y3;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	double a = getLength(x1, y1, x2, y2), b = getLength(x1, y1, x3, y3), c = getLength(x3, y3, x2, y2);
	double p = (a + b + c) / 2;
	printf("%.2lf", sqrt(p*(p-a)*(p-b)*(p-c)));
	return 0;
}
