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
    char str1[31], str2[31], temp[61], *strs, *strc;  // 定义两个字符数组和两个字符指针
    scanf("%s %s", str1, str2);  // 从标准输入读取两个字符串
    // 如果str1的长度大于str2的长度，将strs指向str1，将strc指向str2
    if (strlen(str1) > strlen(str2))
    {
        strs = str1;
        strc = str2;
    }
    // 否则，将strs指向str2，将strc指向str1
    else
    {
        strs = str2;
        strc = str1;
    }
    strcpy(temp, strs);  // 使用strcpy函数将strs指向的字符串复制到temp
    strcat(temp, strs);  // 使用strcat函数将strs指向的字符串追加到temp的末尾
    // 使用strstr函数检查strc指向的字符串是否是temp的子串
    if (strstr(temp, strc) != NULL)
    {
        printf("true");  // 如果是，打印"true"
    }
    else
    {
        printf("false");  // 如果不是，打印"false"
    }
    return 0;  // 函数返回0，表示程序正常结束
}

/*
// 课上C++代码
#include<iostream>
#include<string>
using namespace std;

int test02() {
	string s1, s2;
	cin >> s1 >> s2;

	if (s1.length() < s2.length()) {
		swap(s1, s2);
	}

	for (int i = 0; i < s1.size(); i++) {
		if (s1.find(s2) != -1) {
			cout << "true" << endl;
			return 0;
		}
		char t = s1[0];
		s1.erase(0, 1);
		s1 += t;
		//s1.push_back(t);//从数组尾部插入元素
	}
	cout << "false";
}
int main() {

	string s1, s2;
	cin >> s1 >> s2;
	//线性模拟环（核心：首尾相连，循环模拟 或者  将原序列扩增为原来2倍）
	if (s1.length() < s2.length()) {
		swap(s1, s2);
	}
	s1 += s1;
	if (s1.find(s2) != -1) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	return 0;
}
*/