/*
1.百鸡问题
[问题描述]“百鸡问题”是出自我国古代《张丘建算经》的著名数学问题。大意为:“每只公鸡5元，每只母鸡3元，每3只小鸡1元:现在有100元，买了100只鸡，共有多少种方案?”9小明很喜欢这个故事，他决定对这个问题进行扩展，并使用编程解决: 如果每只公鸡x元，每只母鸡y元，每z只小鸡1元;现在有n元，买了m只鸡，共有多少种方案?[输入描述]输入一行，包含五个整数，分别为问题描述中的x、y、z、n、m
约定1<x,y,z<10，1<n,m <1000。
[输出描述]输出一行，包含一个整数 C，表示有C种方案[样例输入1]533100100
[样例输出1]4
[样例解释1]这就是问题描述中的“百鸡问题”。4种方案分别为:公鸡0只母鸡25只小鸡75只;公鸡4只、母鸡18只、小鸡78只;公鸡8只、鸡11只、小鸡81只;公鸡12只、母鸡4只、小鸡84 只。
[样例输入2]111100100
[样例输出2]5151
*/

// 代码1
#include<stdio.h> 

int main()
{
	int x, y, z, n, m, sum = 0;
	scanf("%d%d%d%d%d", &x, &y, &z, &n, &m);
	for (int num_cock = 0; num_cock <= m / x; num_cock++)
	{
		for (int num_hen = 0; num_hen <= m / y; num_hen++)
		{
			for (int num_chick = 0; num_chick <= m; num_chick += z)
			{
				if (num_cock + num_hen + num_chick == m && num_cock * x + num_hen * y + num_chick / z == n)
				{
					sum++;
					// printf("公鸡 %d 母鸡 %d 小鸡 %d\n", num_cock, num_hen, num_chick);
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}

// 代码2
#include<stdio.h> 

int main()
{
	int x, y, z, n, m, sum = 0;
	scanf("%d%d%d%d%d", &x, &y, &z, &n, &m);
	for (int num_cock = 0; num_cock <= m / x && num_cock * x <= n; num_cock++)
	{
		for (int num_hen = 0; num_hen + num_cock <= m / y && num_cock * x + num_hen * y<= n; num_hen++)
		{
			int num_chick = (n - (num_cock * x + num_hen * y)) * z;
			for (int num_chick = 0; num_chick <= m; num_chick += z)
			{
				if (num_cock + num_hen + num_chick == m)
				{
					sum++;
					// printf("公鸡 %d 母鸡 %d 小鸡 %d\n", num_cock, num_hen, num_chick);
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}