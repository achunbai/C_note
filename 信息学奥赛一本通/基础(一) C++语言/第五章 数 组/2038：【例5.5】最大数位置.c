/*
2038：【例5.5】最大数位置

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 51356     通过数: 30549
【题目描述】
输入n
个整数,存放在数组a[1]
至a[n]
中，输出最大数所在位置(n≤1000
)。

【输入】
第一行，数的个数n
;

第二行，n
个正整数，每个数在232−1
之内。

【输出】
最大数所在位置。

【输入样例】
5
67 43 90 78 32
【输出样例】
3
*/

// 1. 低效，但是能对，先输入，后遍历数组判断
/*
#include <stdio.h>
int main()
{
    int n, i, max, max_i;
    int a[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];
    max_i = 0;
    for (i = 1; i < n; i++)
        if (a[i] > max)
        {
            max = a[i];
            max_i = i;
        }
    printf("%d\n", max_i + 1);
    return 0;
}
*/

// 2. 高效，一边输入，一边判断
#include <stdio.h>

int main()
{
	int num[1001] = { 0 }, n, pos = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num[i]);
		if (num[pos] < num[i])
		{
			pos = i;
		}
	}
	printf("%d", pos);
	return 0;
}