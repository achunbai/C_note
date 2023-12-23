/*
2046：【例5.15】替换字母

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 51677     通过数: 28150
【题目描述】
在应用计算机编辑文档的时候，我们经常遇到替换任务。如把文档中的“电脑”都替换成“计算机”。现在请你编程模拟一下这个操作。

【输入】
输入两行内容，第1行是原文(长度不超过200
个字符)，第2
行包含以空格分隔的两个字符A
和B
，要求将原文中所有的字符A
都替换成字符B
，注意：区分大小写字母。

【输出】
一行，输出替换后的结果。

【输入样例】
I love China. I love Beijing.
I U
【输出样例】
U love China. U love Beijing.
*/
#include <stdio.h>
#include <string.h>

int main()
{
	char str[201], co, cr;
	gets(str);
	scanf("%c %c", &co, &cr);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == co)
		{
			str[i] = cr;
		}
	}
	printf(str);
	return 0;
}