/*
1164：digit函数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 37767     通过数: 24219
【题目描述】
在程序中定义一函数digit(n,k)
，它能分离出整数n
从右边数第k
个数字。

【输入】
正整数n
和k
。

【输出】
一个数字。

【输入样例】
31859 3
【输出样例】
8
*/
#include <stdio.h>

// digit函数的实现
int digit(int n, int k)
{
    // 如果k不等于1，那么我们将n除以10，然后递归调用digit函数，k减1
    if(k != 1)
    {
        return digit(n/10, k - 1);
    }
    // 如果k等于1，那么我们返回n除以10的余数，也就是n的最后一位数字
    else if(k == 1)
    {
        return n % 10;
    }
    // 其他情况返回-1，实际上这种情况不会发生，因为题目已经限定了k的取值范围
    else
    {
        return -1;
    }
}

int main()
{
    int m, n;
    // 读取输入的m和n
    scanf("%d %d", &m, &n);
    // 调用digit函数，打印结果
    printf("%d\n", digit(m, n));
    return 0;
}