/*
1095：数1的个数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 61162     通过数: 43131
【题目描述】
给定一个十进制正整数n(1≤n≤10000)
，写下从1
到n
的所有整数，然后数一下其中出现的数字“1”的个数。

例如当n=2
时，写下1,2
。这样只出现了1
个“1”；当n=12
时，写下1，2，3，4，5，6，7，8，9，10，11，12
。这样出现了5
个“1”。

【输入】
正整数n
。1≤n≤10000
。

【输出】
一个正整数，即“1”的个数。

【输入样例】
12
【输出样例】
5
*/
// 1. 利用字符串，将数字转换为字符串，然后遍历字符串，判断是否为1
// sprintf()函数可以将数字转换为字符串，用法为：
// sprintf(str, "%d", i);
// 其中str为字符串，%d为数字，i为要转换的数字
/*
#include <stdio.h>
#include <string.h>
int main()
{
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char str[10];
        sprintf(str, "%d", i); // 将数字转换为字符串
        for (int j = 0; j < strlen(str); j++)
        {
            if (str[j] == '1')
            {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
*/

// 2. 利用数组，将数字转换为数组，然后遍历数组，判断是否为1
/*
#include <stdio.h>
int main()
{
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int arr[10], len = 0;
        int tmp = i;
        while (tmp)
        {
            arr[len++] = tmp % 10;
            tmp /= 10;
        }
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == 1)
            {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
*/

// 3. 利用while循环，每次取个位数，判断是否为1，然后除以10，直到为0
#include <stdio.h>

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 == 1)
            {
                count++;
            }
            tmp /= 10;
        }
    }
    printf("%d", count);
    return 0;
}

// 4. 因为其最大值为10000，所以可以直接分位判断
/*
#include <stdio.h>

int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (i % 10 == 1)
		{
			sum++;
		}
		if (i / 10 % 10 == 1)
		{
			sum++;
		}
		if (i / 100 % 10 == 1)
		{
			sum++;
		}
		if (i / 1000 % 10 == 1)
		{
			sum++;
		}
		if (i / 10000 % 10 == 1)
		{
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}
*/
