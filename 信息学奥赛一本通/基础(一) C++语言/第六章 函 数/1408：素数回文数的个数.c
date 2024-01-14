/*
1408：素数回文数的个数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 36711     通过数: 23195
【题目描述】
求11到n之间（包括n），既是素数又是回文数的整数有多少个。

【输入】
一个大于11小于1000的整数n。

【输出】
11到n之间的素数回文数个数。

【输入样例】
23
【输出样例】
1
【提示】
提示:

回文数指左右对称的数，如：292，333。
*/
#include <stdio.h>
#include <stdlib.h>

// 获取质数的函数，返回一个数组，数组的索引是数字，值为1表示不是质数，值为0表示是质数
int *GetPrime(int MaxNum)
{
    int *Prime = (int*)calloc(MaxNum + 1, sizeof(int));
    Prime[0] = Prime[1] = 1;  // 0和1不是质数
    for (int i = 2; i <= MaxNum; i++)
    {
        for (int j = i + i; j <= MaxNum; j += i)
        {
            if(!Prime[j])
            {
                Prime[j] = 1;  // 标记非质数
            }
        }
    }
    return Prime;
}

int main()
{
    int n, cnt = 0, num;
    scanf("%d", &n);
    int *Prime = GetPrime(n);  // 获取质数标记数组
    for (int i = 11; i <= n && i < 100 ; i += 11)  // 生成两位回文数并检查是否是素数
    {
        if(!Prime[i])
        {
            cnt++;
        }
    }
    for (int i = 1 ; i < 10 ; i++)  // 生成三位回文数并检查是否是素数
    {
        for(int j = 0; j < 10; j++)
        {
            num = i * 100 + j * 10 + i;
            if(num <= n)
            {
                if(!Prime[num])
                {
                    cnt++;
                }
            }
            else
            {
                break;
            }
        }
    }
    printf("%d\n", cnt);  // 输出素数回文数的个数
    free(Prime);  // 释放内存
    return 0;
}
