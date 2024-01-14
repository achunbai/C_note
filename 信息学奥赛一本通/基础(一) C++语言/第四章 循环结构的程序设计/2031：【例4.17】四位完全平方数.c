/*
2031：【例4.17】四位完全平方数

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 46110     通过数: 25161
【题目描述】
输出所有形如aabb的四位完全平方数（即前两位数字相等，后两位数字也相等）。

【输入】
无

【输出】
由小到大输出，每个数占一行。

【输入样例】
无
【输出样例】
无
*/

// 先计算所有四位完全平方数，再判断是否为aabb型
/*
#include <stdio.h>

int main()
{
	int tmp, q, b, s, g;
	for (int i = 32; i < 100; i++)
	{
		tmp = i * i;
		q = tmp / 1000;
		b = tmp / 100 % 10;
		s = tmp / 10 % 10;
		g = tmp % 10;
		if (q == b && s == g)
		{
			printf("%d\n", tmp);
		}
	}
	return 0;
}
*/

// 先列出所有四位数，再判断是否为完全平方数
#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            int num = i * 1100 + j * 11;
            int tmp = (int)sqrt(num);
            if (tmp * tmp == num)
            {
                printf("%d\n", num);
            }
        }
    }
    return 0;
}