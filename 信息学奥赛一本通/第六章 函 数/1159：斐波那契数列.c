/*
1159：斐波那契数列

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 60403     通过数: 41759
【题目描述】
用递归函数输出斐波那契数列第n项。0,1，1，2，3，5，8，13……

【输入】
一个正整数n,表示第n项。

【输出】
第n项是多少。

【输入样例】
3
【输出样例】
1
*/

// fibonacci函数调用自身来计算斐波那契数列的前两项的和。
// 斐波那契数列的定义：
// 第1项是0，第2项和第3项是1，从第4项开始，每一项都是前两项的和。
// 使用递归的方式来计算斐波那契数列的第n项
// 即fibonacci(n - 1) + fibonacci(n - 2)。
#include <stdio.h>

int fibonacci(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2 || n == 3)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fibonacci(n));
	return 0;
}

/*
#include <stdio.h>

#define MAX 1000  // 定义一个宏，表示斐波那契数列的最大项数

int fib[MAX];  // 定义一个数组，用于存储斐波那契数列的项

// 定义一个函数，用于计算斐波那契数列的第n项
int fibonacci(int n)
{
    // 如果n等于1，返回0，因为斐波那契数列的第1项是0
    if (n == 1)
    {
        return 0;
    }
    // 如果n等于2或3，返回1，因为斐波那契数列的第2项和第3项都是1
    else if (n == 2 || n == 3)
    {
        return 1;
    }
    // 如果fib[n]已经被计算过，直接返回fib[n]
    else if (fib[n] != 0)
    {
        return fib[n];
    }
    // 如果fib[n]还没有被计算过，计算fib[n]，并将结果存储在fib[n]中
    else
    {
        fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return fib[n];
    }
}

int main()
{
    int n;  // 定义一个整数n，用于存储输入的数字
    scanf("%d", &n);  // 从标准输入读取一个数字
    printf("%d\n", fibonacci(n));  // 打印斐波那契数列的第n项
    return 0;  // 函数返回0，表示程序正常结束
}
*/