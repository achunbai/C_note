/*
1083：计算星期几

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 95479     通过数: 42396
【题目描述】
假设今天是星期日，那么过ab
天之后是星期几？

【输入】
两个正整数a
，b
，中间用单个空格隔开。0<a≤100,0<b≤10000
。

【输出】
一个字符串，代表过ab
天之后是星期几。

其中，Monday是星期一，Tuesday是星期二，Wednesday是星期三，Thursday是星期四，Friday是星期五，Saturday是星期六，Sunday是星期日。

【输入样例】
3 2000
【输出样例】
Tuesday
*/
#include <stdio.h>

int main()
{
	int a, b, result = 1;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < b; i++) // 循环b次，求a的b次方，防止数据过大溢出，每次求余
	{
		result *= a;    // 求a的b次方
		result %= 7;    // 求余
	}
	switch (result) // 判断星期几，注意0为周日
	{
	case 1:
		printf("Monday");
		break;
	case 2:
		printf("Tuesday");
		break;
	case 3:
		printf("Wednesday");
		break;
	case 4:
		printf("Thursday");
		break;
	case 5:
		printf("Friday");
		break;
	case 6:
		printf("Saturday");
		break;
	case 0:
		printf("Sunday");
		break;
	}
	return 0;
}