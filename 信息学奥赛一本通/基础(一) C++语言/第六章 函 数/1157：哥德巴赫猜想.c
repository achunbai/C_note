/*
1157：哥德巴赫猜想

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 52255     通过数: 30210
【题目描述】
哥德巴赫猜想的命题之一是:大于6 的偶数等于两个素数之和。编程将6～100所有偶数表示成两个素数之和。

【输入】
(无）

【输出】
分行输出：

例如:

6=3+3

8=3+5

...

（每个数只拆开一次，请保证第一个加数最小）

【输入样例】
（无）
【输出样例】
（无）
*/

#include <stdio.h>
#include <stdlib.h>

int* GetPrime(int n)
{
    int* prime = (int*)calloc(n + 1, sizeof(int));
    for (int i = 2; i <= n; i++)
    {
        for(int j = i + i; j <= n; j += i)
            if(!prime[i])
                prime[j] = 1;
    }
    return prime;
}

int main()
{
    int* prime = GetPrime(100);
    for(int i = 6; i <= 100; i += 2)
        for(int j = 2; j < i; j++)
            if(!prime[j] && !prime[i - j])
            {
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
    free(prime);
    return 0;
}
