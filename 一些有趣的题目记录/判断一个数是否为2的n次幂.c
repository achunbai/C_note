/*
### 判断一个数是否为2的n次幂，是返回1，不是返回0

注意是返回值，需要自定义一个新函数
*/

/*
最简单的求法，不断除以2，如果最后等于1，说明是2的n次幂
int isPowerOfTwo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    while (n % 2 == 0)
    {
        n /= 2;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
*/

#include <stdio.h>

// 位运算，如果是2的n次幂，那么二进制表示中只有一个1
int isPowerOfTwo(int num)
{
    if ((num & (num - 1)) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", isPowerOfTwo(num));
    return 0;
}