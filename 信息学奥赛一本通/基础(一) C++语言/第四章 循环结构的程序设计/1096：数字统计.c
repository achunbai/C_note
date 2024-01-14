/*
1096：数字统计

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 54591     通过数: 38261
【题目描述】
请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。

   比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。

【输入】
输入共 1 行，为两个正整数 L 和 R，之间用一个空格隔开。

【输出】
输出共 1 行，表示数字 2 出现的次数。

【输入样例】
2 22
【输出样例】
6
【提示】
样例 #2：

2 100
样例 #2：

20
*/
// 1. 利用字符串，将数字转换为字符串，然后遍历字符串，判断是否为2
// sprintf()函数可以将数字转换为字符串，用法为：
// sprintf(str, "%d", i);
// 其中str为字符串，%d为数字，i为要转换的数字
/*
#include <stdio.h>
#include <string.h>
int main()
{
    int L, R, sum = 0;
    scanf("%d%d", &L, &R);
    for (int i = L; i <= R; i++)
    {
        char str[10];
        sprintf(str, "%d", i); // 将数字转换为字符串
        for (int j = 0; j < strlen(str); j++)
        {
            if (str[j] == '2')
            {
                sum++;
            }
        }
    }
}
*/

// 2. 利用数组，将数字转换为数组，然后遍历数组，判断是否为2
/*
#include <stdio.h>
int main()
{
    int L, R, sum = 0;
    scanf("%d%d", &L, &R);
    for (int i = L; i <= R; i++)
    {
        int arr[10], count = 0;
        int tmp = i;
        while (tmp)
        {
            arr[count++] = tmp % 10;
            tmp /= 10;
        }
        for (int j = 0; j < count; j++)
        {
            if (arr[j] == 2)
            {
                sum++;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
*/

// 3. 利用while循环，每次取个位数，判断是否为2，然后除以10，直到为0
#include <stdio.h>

int main()
{
    int L, R, sum = 0;
    scanf("%d%d", &L, &R);
    for (int i = L; i <= R; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 == 2)
            {
                sum++;
            }
            tmp /= 10;
        }
    }
    printf("%d", sum);
    return 0;
}

// 4.直接分位判断，修改1095的代码
/*
#include <stdio.h>

int main()
{
	int L, R, sum = 0;
	scanf("%d %d", &L, &R);
	for (int i = L; i <= R; i++)
	{
		if (i % 10 == 2)
		{
			sum++;
		}
		if (i / 10 % 10 == 2)
		{
			sum++;
		}
		if (i / 100 % 10 == 2)
		{
			sum++;
		}
		if (i / 1000 % 10 == 2)
		{
			sum++;
		}
		if (i / 10000 % 10 == 2)
		{
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}
*/