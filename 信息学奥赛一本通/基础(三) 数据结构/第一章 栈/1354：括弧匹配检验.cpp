//
//  1354：括弧匹配检验.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/12.
//

/*
 1354：括弧匹配检验

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 52905     通过数: 17677
 【题目描述】
 假设表达式中允许包含两种括号：圆括号和方括号，其嵌套的顺序随意，如（［ ］（））或［（［ ］［ ］）］等为正确的匹配，［（ ］）或（［ ］（ ）或 ( ( ) ) ）均为错误的匹配。

 现在的问题是，要求检验一个给定表达式中的括弧是否正确匹配？

 输入一个只包含圆括号和方括号的字符串，判断字符串中的括号是否匹配，匹配就输出 “OK” ，不匹配就输出“Wrong”。输入一个字符串：［（［］［］）］，输出：OK。

 【输入】
 输入仅一行字符（字符个数小于255
 ）。

 【输出】
 匹配就输出 “OK” ，不匹配就输出“Wrong”。

 【输入样例】
 [(])
 【输出样例】
 Wrong
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    string str;
    cin >> str;
    stack<char> stk;
    for(auto c:str)
    {
        switch (c)
        {
            case '(':
            case '[':
            case '{':
                stk.push(c);
                break;
            case ')':
                if (stk.empty())
                {
                    cout << "Wrong" << endl;
                    return 0;
                }
                else if (stk.top() != '(')
                {
                    cout << "Wrong" << endl;
                    return 0;
                }
                else
                    stk.pop();
                break;
            case ']':
                if (stk.empty())
                {
                    cout << "Wrong" << endl;
                    return 0;
                }
                else if (stk.top() != '[')
                {
                    cout << "Wrong" << endl;
                    return 0;
                }
                else
                    stk.pop();
                break;
            case '}':
                if (stk.empty())
                {
                    cout << "Wrong" << endl;
                    return 0;
                }
                else if (stk.top() != '{')
                {
                    cout << "Wrong" << endl;
                    return 0;
                }
                else
                    stk.pop();
                break;
            default:
                break;
        }
    }
    if(stk.empty())
        cout << "OK" << endl;
    else
        cout << "Wrong" << endl;
    return 0;
}
