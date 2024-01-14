/*
2035：【例5.2】平移数据

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 54255     通过数: 35737
【题目描述】
将a
数组中第一个元素移到数组末尾,其余数据依次往前平移一个位置。

【输入】
第一行为数组a
的元素个数；

第二行为n
个小于1000
的正整数。

【输出】
平移后的数组元素，每个数用一个空格隔开。

【输入样例】
10
1 2 3 4 5 6 7 8 9 10
【输出样例】
2 3 4 5 6 7 8 9 10 1
*/

// 1. 老实移位输出
#include <stdio.h>

int main()
{
	int num[1000], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	int tmp = num[0];
	for (int i = 0; i < n; i++)
	{
		num[i] = num[i + 1];
	}
	num[n - 1] = tmp;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

// 2. 偷鸡，直接从第二个元素开始输出，然后将首个元素最后输出
/*
#include <stdio.h>
int main()
{
    int n, a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);    // 输入数组
    }
    for (int i = 1; i < n; i++)
    {
        printf("%d ", a[i]);    // 输出数组
    }
    printf("%d", a[0]);
    return 0;
}
*/

// 3. 偷鸡2，直接从输入开始就从第二个元素开始输入，最后再输入第一个元素
/*
#include <stdio.h>

int main()
{
	int num[1000], n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	scanf("%d", &num[0]);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}
*/
