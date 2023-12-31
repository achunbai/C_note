/*
2036：【例5.3】开关门

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 50261     通过数: 32246
【题目描述】
宾馆里有n(2≤n≤1000)
个房间，从1∼n
编了号。第一个服务员把所有的房间门都打开了，第二个服务员把所有编号是2
的倍数的房间“相反处理”，第三个服务员把所有编号是3
的倍数的房间作“相反处理”…，以后每个服务员都是如此。当第n
个服务员来过后，哪几扇门是打开的。（所谓“相反处理”是：原来开着的门关上，原来关上的门打开。）

【输入】
房间数n
。

【输出】
一行，由小到大的打开门的房间序号，各序号之间用一个空格隔开。

【输入样例】
100
【输出样例】
1 4 9 16 25 36 49 64 81 100
*/

// 1. 用数组记录每个房间的状态，然后输出
#include <stdio.h>

int main()
{
	int door[1001] = { 0 }, n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			door[j] = !door[j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (door[i])
		{
			printf("%d ", i);
		}
	}
	return 0;
}

// 2. 用一个变量记录每个房间的状态，然后输出
/*
#include <stdio.h>
int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        flag = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = !flag;
            }
        }
        if (flag)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
*/
