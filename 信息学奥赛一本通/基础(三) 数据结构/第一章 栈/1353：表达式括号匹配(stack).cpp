//
//  1353：表达式括号匹配(stack).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/17.
//

/*
 1353：表达式括号匹配(stack)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 39875     通过数: 20801
 【题目描述】
 假设一个表达式有英文字母（小写）、运算符（+，—，∗，/
 ）和左右小（圆）括号构成，以“@
 ”作为表达式的结束符。请编写一个程序检查表达式中的左右圆括号是否匹配，若匹配，则返回“YES
 ”；否则返回“NO
 ”。表达式长度小于255
 ，左圆括号少于20
 个。

 【输入】
 一行数据，即表达式。

 【输出】
 一行，即“YES
 ” 或“NO
 ”。

 【输入样例】
 2*(x+y)/(1-x)@
 【输出样例】
 YES
 【提示】
 【样例输入2】

 (25+x)*(a*(a+b+b)@
 【样例输出2】

 NO
 */

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char* argv[])
{
    string str;
    cin >> str;
    stack<int> kh;
    
    for(auto c:str)
    {
        if(c == '(')
        {
            kh.push(c);
        }
        if(c == ')')
        {
            if(kh.empty())
            {
                cout << "NO" << endl;
                return 0;
            }
            else
            {
                kh.pop();
            }
        }
    }
    if(!kh.empty())
        cout << "NO" << endl;
    else
        cout << "YES" <<endl;
    return 0;
}
