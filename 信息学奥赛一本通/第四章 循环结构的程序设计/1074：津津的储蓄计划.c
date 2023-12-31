/*
1074：津津的储蓄计划

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 108964     通过数: 50993
【题目描述】
津津的零花钱一直都是自己管理。每个月的月初妈妈给津津300元钱，津津会预算这个月的花销，并且总能做到实际花销和预算的相同。

为了让津津学习如何储蓄，妈妈提出，津津可以随时把整百的钱存在她那里，到了年末她会加上20％还给津津。因此津津制定了一个储蓄计划：每个月的月初，在得到妈妈给的零花钱后，如果她预计到这个月的月末手中还会有多于100元或恰好100元，她就会把整百的钱存在妈妈那里，剩余的钱留在自己手中。

例如11月初津津手中还有83元，妈妈给了津津300元。津津预计11月的花销是180元，那么她就会在妈妈那里存200元，自己留下183元。到了11月月末，津津手中会剩下3元钱。

现在请你根据2004年1月到12月每个月津津的预算，判断会不会出现这种情况。如果不会，计算到2004年年末，妈妈将津津平常存的钱加上20％还给津津之后，津津手中会有多少钱。

【输入】
包括12行数据，每行包含一个小于350的非负整数，分别表示1月到12月津津的预算。

【输出】
只包含一个整数。如果储蓄计划实施过程中出现某个月钱不够用的情况，输出-X，X表示出现这种情况的第一个月；否则输出到2004年年末津津手中会有多少钱。

【输入样例】
290
230
280
200
300
170
340
50 
90 
80 
200
60
【输出样例】
-7
【提示】
【[样例2】

输入：

290
230 
280 
200 
300 
170 
330 
50 
90 
80 
200 
60
输出：

1580
*/

#include <stdio.h>

int main()
{
	int budget, sum = 0, remain = 0, month = 0;
	for (int i = 0; i < 12; i++)
	{
		scanf("%d", &budget);
		remain += 300 - budget;
		if ( remain / 100 > 0)
		{
			sum += remain - remain % 100;
			remain %= 100;
		}
		else if (remain < 0 && !month) // 注意输出第一个为负的月份
		{
			month = i + 1;
		}
	}
	if (month)
	{
		printf("-%d", month);
	}
	else
	{
		printf("%.0lf", sum * 1.2 + remain);	// 手里的钱分为两部分，第一部分是存妈妈那里整百的，计算利息，第二部分是不足整百的，不计算利息
	}
	return 0;
}