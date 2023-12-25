/*
2050：【例5.20】字串包含

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 30487     通过数: 12783
【题目描述】
字符串移位包含问题。

对于一个字符串来说，定义一次循环移位操作为：将字符串的第一个字符移动到末尾形成新的字符串。

给定两个字符串s1
�
1
和s2
�
2
，要求判定其中一个字符串是否是另一字符串通过若干次循环移位后的新字符串的子串。例如CDAA是由AABCD两次移位后产生的新串BCDAA的子串，而ABCD与ACBD则不能通过多次移位来得到其中一个字符串是新串的子串。

【输入】
一行，包含两个字符串，中间由单个空格隔开。字符串只包含字母和数字，长度不超过30
30
。

【输出】
如果一个字符串是另一字符串通过若干次循环移位产生的新串的子串，则输出true，否则输出false。

【输入样例】
AABCD CDAA
【输出样例】
true
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[31], str2[31], temp[61], *strs, *strc;
	int flag = 0;
	scanf("%s %s", str1, str2);
	if (strlen(str1) > strlen(str2))
	{
		strs = str1;
		strc = str2;
	}
	else
	{
		strs = str2;
		strc = str1;
	}
	strcpy(temp, strs);
	strcat(temp, strs);
	if (strstr(temp, strc) != NULL)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	return 0;
}