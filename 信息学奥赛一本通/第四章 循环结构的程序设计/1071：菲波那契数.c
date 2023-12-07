/*
1071：菲波那契数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 135252     通过数: 71133
【题目描述】
菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。给出一个正整数k，要求菲波那契数列中第k个数是多少。

【输入】
输入一行，包含一个正整数k。（1 ≤ k ≤ 46）

【输出】
输出一行，包含一个正整数，表示菲波那契数列中第k个数的大小。

【输入样例】
19
【输出样例】
4181
*/

/*
#include <stdio.h>

int main() 
{
    int bef2 = 1, bef1 = 1, num, n;
    scanf("%d", &n);
    if (n < 3)
    {
        printf("1");
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            num = bef2 + bef1;
            bef2 = bef1;
            bef1 = num;
        }
        printf("%d", num);
    }
    return 0;
}
*/

#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);
    int a = 1, b = 1, c;
    for (int i = 3; i <= k; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%d", b);
    return 0;
}