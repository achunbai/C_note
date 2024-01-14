/*
1413：确定进制

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 23311     通过数: 12969
【题目描述】
6×9=42对于十进制来说是错误的，但是对于13进制来说是正确的。即, 6(13)× 9(13)= 42(13)， 而 42(13)=4×131+2×130=54(10)。

你的任务是写一段程序，读入三个整数p、q和 r，然后确定一个进制 B(2<=B<=40) 使得 p × q = r。 如果 B 有很多选择, 输出最小的一个。

例如：p=11, q=11, r=121.则有11(3)× 11(3)= 121(3)因为 11(3)= 1 × 31+ 1 × 30= 4(10)和121(3)=1×32+2×31+1×30=16(10)。对于进制 10，同样有11(10)× 11(10)= 121(10)。这种情况下，应该输出 3。如果没有合适的进制，则输出 0。

【输入】
一行，包含三个整数p、q、r。 p、q、r的所有位都是数字，并且1 ≤ p、q、r ≤ 1,000,000。

【输出】
一个整数：即使得p×q=r成立的最小的B。如果没有合适的B，则输出0。

【输入样例】
6 9 42
【输出样例】
13
*/
#include <stdio.h>
#include <math.h>

// 获取一个数的最大数字
int GetMaxNum(int Num)
{
    int MaxNum = 0;
    while(Num)
    {
        int Digit = Num % 10;
        if(Digit > MaxNum)
        {
            MaxNum = Digit;
        }
        Num /= 10;
    }
    return MaxNum;
}

// 将一个数从给定的进制转换为十进制
long long ConvertToDecimal(int Num, int bit)
{
    long long Result = 0, factor = 1;
    while (Num)
    {
        Result += (Num % 10) * factor;
        Num /= 10;
        factor *= bit;
    }
    return Result;
}

int main()
{
    int p, q, r, MaxNum;
    long long p_dec, q_dec, r_dec;
    scanf("%d %d %d", &p, &q, &r);
    // 找到p、q和r中的最大数字
    MaxNum = GetMaxNum(p) > GetMaxNum(q) ? GetMaxNum(p) : GetMaxNum(q);
    MaxNum = MaxNum > GetMaxNum(r) ? MaxNum : GetMaxNum(r);
    int found = 0;
    // 从最大数字+1开始尝试不同的进制
    for (int i = MaxNum + 1; i < 41; i++)
    {
        p_dec = ConvertToDecimal(p, i);
        q_dec = ConvertToDecimal(q, i);
        r_dec = ConvertToDecimal(r, i);
        // 如果找到一个可以使p×q=r的进制，输出这个进制
        if(p_dec * q_dec == r_dec)
        {
            printf("%d\n", i);
            found = 1;
            break;
        }
    }
    // 如果没有找到合适的进制，输出0
    if (!found)
    {
        printf("0\n");
    }
    return 0;
}
