/*
2064：【例2.1】交换值

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 134304     通过数: 73209
【题目描述】
输入两个正整数a和b，试交换a、b的值（使a的值等于b，b的值等于a）。

【输入】
输入两个正整数a和b。

【输出】
输出a与b交换值后的结果。

【输入样例】
2 3
【输出样例】
3 2
*/

/*
#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d %d", b, a);
}
*/
#include<stdio.h>

// 把a、b看做数轴上的点，围绕两点间的距离来进行计算。
void exchange(int* num1, int* num2)
{
	*num1 -= *num2;
	*num2 += *num1;
	*num1 = *num2 - *num1;
}

void exchange1(int* num1, int* num2)
{
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

// 由异或运算的特点决定，通过异或运算能够使数据中的某些位翻转，其他位不变，这就意味着任意一个数与任意一个给定的值连续异或两次，值不变。
void exchange2(int* num1, int* num2)
{
	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;
}

int main()
{
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	exchange(&num1, &num2);
	printf("%d %d\n", num1, num2);
	exchange1(&num1, &num2);
	printf("%d %d\n", num1, num2);
	exchange2(&num1, &num2);
	printf("%d %d\n", num1, num2);
	return 0;
}