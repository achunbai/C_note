/*
1086：角谷猜想

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 103885     通过数: 62693
【题目描述】
谓角谷猜想，是指对于任意一个正整数，如果是奇数，则乘3
加1
，如果是偶数，则除以2
，得到的结果再按照上述规则重复处理，最终总能够得到1
。如，假定初始整数为5
，计算过程分别为16
、8
、4
、2
、1
。程序要求输入一个整数，将经过处理得到1
的过程输出来。

【输入】
一个正整数n
(n≤2,000,000
)。

【输出】
从输入整数到1
的步骤，每一步为一行，每一部中描述计算过程。最后一行输出"End"。如果输入为1
，直接输出"End"。

【输入样例】
5
【输出样例】
5*3+1=16
16/2=8
8/2=4
4/2=2
2/2=1
End
【提示】
no
*/
#include <stdio.h>

// while循环版本
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int result = n, tmp;
//	while (result != 1)
//	{
//		if (result % 2)
//		{
//			tmp = result;
//			result = result * 3 + 1;
//			printf("%d*3+1=%d\n", tmp, result);
//		}
//		else
//		{
//			tmp = result;
//			result /= 2;
//			printf("%d/2=%d\n", tmp, result);
//
//		}
//	}
//	printf("End");
//	return 0;
//}

// do-while循环版本
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int result = n, tmp;
//	if (result != 1)
//	{
//		do
//		{
//			if (result % 2)
//			{
//				tmp = result;
//				result = result * 3 + 1;
//				printf("%d*3+1=%d\n", tmp, result);
//			}
//			else
//			{
//				tmp = result;
//				result /= 2;
//				printf("%d/2=%d\n", tmp, result);
//
//			}
//		} while (result != 1);
//	}
//	printf("End");
//	return 0;
//}

// for循环版本
int main()
{
	int n;
	scanf("%d", &n);
	int result = n, tmp;
	for ( ; result != 1; )
	{
		if (result % 2)
		{
			tmp = result;
			result = result * 3 + 1;
			printf("%d*3+1=%d\n", tmp, result);
		}
		else
		{
			tmp = result;
			result /= 2;
			printf("%d/2=%d\n", tmp, result);

		}
	}
	printf("End");
	return 0;
}