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
/*
// 课上C++代码

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int N = 2e2 + 10;
//char ch[N];
//void test01() {
//	gets_s(ch);
//	char A, B;
//	cin >> A >> B;
//	for (int i = 0; i < strlen(ch); i++) {
//		if (ch[i] == A) ch[i] = B;
//	}
//	cout << ch << endl;
//}
int main() {
	
	string s;
	getline(cin, s);
	char A, B;   cin >> A >> B;

	//for (int i = 0; i < s.size(); i++) {
	//	if (s[i] == A) s[i] = B;
	//}
	//C++11 特性  for range  
	for (auto& c : s) {//引用类型type& b=a,相当于给a起了一个别名叫b
		if (c == A) c = B;
	}
	cout << s << endl;
	return 0;
}
*/