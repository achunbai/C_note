/*
1066：满足条件的数累加

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 85718     通过数: 68616
【题目描述】
将正整数m
和n
之间(包括m
和n
)能被17
整除的数累加，其中，0<m<n<1000
。

【输入】
一行，包含两个整数m
和n
，其间，以一个空格间隔。

【输出】
输出一行，包行一个整数，表示累加的结果。

【输入样例】
50 85
【输出样例】
204
*/

/*
#include <stdio.h>

int main() 
{
    int m, n, sum = 0;
    scanf("%d %d", &m, &n);
    for (int i = m + 17 - (m % 17); i <= n; i += 17)    //m+17-(m%17)是m的下一个17的倍数
    // 如果需要包括m，则需要将i的起始值改为 i=m+(17-m%17)%17，即
    // for (int i = m + (17 - m % 17) % 17; i <= n; i += 17)
    {
        sum += i;
    }
    printf("%d", sum);
    return 0;
}
*/
#include <stdio.h>

int main()
{
    int m, n, sum = 0;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        if (i % 17 == 0)
        {
            sum += i;
        }
    }
    printf("%d", sum);
    return 0;
}