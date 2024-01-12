/*
2049：【例5.19】字符串判等

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 41356     通过数: 16159
【题目描述】
判断两个由大小写字母和空格组成的字符串在忽略大小写，且忽略空格后是否相等。

【输入】
两行，每行包含一个字符串。

【输出】
若两个字符串相等，输出YES，否则输出NO。

【输入样例】
a A bb BB ccc CCC
Aa BBbb CCCccc
【输出样例】
YES
【提示】
本评测系统基于linux，不支持函数strupr、strlwr。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 函数：移除字符串中的空格，并将所有字符转换为小写
void remove_space_and_to_lower(char* str)
{
    int j = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        // 如果当前字符不是空格，将其转换为小写并存储在str[j]中
        if (str[i] != ' ')
        {
            str[j++] = tolower(str[i]);
        }
        else
        {
            // 如果当前字符是空格，跳过它
            continue;
        }
    }
    // 在字符串的末尾添加null字符
    str[j] = 0;
}

int main()
{
    // 定义两个字符串str1和str2
    char str1[10000], str2[10000];
    // 从标准输入读取两个字符串
    fgets(str1, 10000, stdin);
    fgets(str2, 10000, stdin);
    // 移除字符串中的空格，并将所有字符转换为小写
    remove_space_and_to_lower(str1);
    remove_space_and_to_lower(str2);
    // 比较两个字符串是否相等
    if (strcmp(str1, str2) == 0)
    {
        // 如果两个字符串相等，输出"YES"
        printf("YES");
    }
    else
    {
        // 如果两个字符串不相等，输出"NO"
        printf("NO");
    }
    return 0;
}

/*
// 课上C++代码
#include<iostream>
#include<string>
using namespace std;

void tolower(string& s) {

	for (auto& c : s) {
		if (c >= 'A' && c <= 'Z') c += 32;
	}
}
int main() {
	
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	tolower(s1);
	tolower(s2);
	string str1, str2;
	for (auto c : s1) if (c != ' ') str1 += c;
	for (auto c : s2) if (c != ' ') str2 += c;

	if (str1 == str2) cout << "YES";
	else cout << "NO";
	return 0;
}
*/