/*
2044：【例5.12】回文字串

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 33697     通过数: 14201
【题目描述】
输入一串字符,字符个数不超过100
,且以“.”结束。 判断它们是否构成回文。

【输入】
一行字符串。

【输出】
是否为回文串。是输出“Yes”，否输出“No。”

【输入样例】
abccb
【输出样例】
No
*/

// 课上示例
/*
#include <stdio.h>
#include <string.h>
int  main(){
	char str[100];
	scanf("%s", str);
	int i = 0;
	int j = strlen(str) - 2;
	while (i < j) {
		if (str[i] != str[j]) {
			printf("No");
			return 0;
		}
		i++;
		j--;
	}
	printf("Yes");
	return 0;
}
*/

// 我的版本1
#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	gets(str);
	int length = strlen(str);
	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - i - 2])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}

// 我的版本2
/*
#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	gets(str);
	int length = 0;
	while (str[length] != '.')
	{
		length++;
	}
	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - i - 1])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}
*/