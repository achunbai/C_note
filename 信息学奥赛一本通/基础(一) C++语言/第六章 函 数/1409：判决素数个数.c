/*
1409：判决素数个数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 36768     通过数: 22211
【题目描述】
输入两个整数X
和Y
，输出两者之间的素数个数（包括X
和Y
）。

【输入】
两个整数X
和Y
（1≤X,Y≤105
）。

【输出】
输出一个整数，表示X
，Y
之间的素数个数（包括X
和Y
）。

【输入样例】
1 100
【输出样例】
25
*/
#include <stdio.h>
#include <stdlib.h>

// 获取质数的函数，返回一个数组，数组的索引是数字，值为1表示不是质数，值为0表示是质数
int *GetPrime(int MaxNum)
{
    int *Prime = (int*)calloc(MaxNum + 1, sizeof(int));
    Prime[0] = Prime[1] = 1;  // 0和1不是质数
    for (int i = 2; i * i <= MaxNum; i++)  // 只需要遍历到根号MaxNum
    {
        if (!Prime[i])  // 如果i是质数，那么i的倍数不是质数
        {
            for (int j = i * i; j <= MaxNum; j += i)
            {
                Prime[j] = 1;  // 标记非质数
            }
        }
    }
    return Prime;
}

int main()
{
    int x, y, cnt = 0;
    scanf("%d %d", &x, &y);
    int *Prime = GetPrime(y);  // 获取质数标记数组
    for (int i = x; i <= y; i++)  // 遍历x到y之间的所有数字
    {
        if(!Prime[i])  // 如果是质数，计数器加1
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);  // 输出素数的个数
    free(Prime);  // 释放内存
    return 0;
}
