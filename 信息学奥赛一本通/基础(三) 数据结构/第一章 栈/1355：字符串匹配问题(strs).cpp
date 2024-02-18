//
//  1355：字符串匹配问题(strs).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/12.
//

/*
 1355：字符串匹配问题(strs)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 31184     通过数: 11188
 【题目描述】
 字符串中只含有括号 (),[],<>,{},判断输入的字符串中括号是否匹配。如果括号有互相包含的形式，从内到外必须是<>,(),[],{}，例如。输入: [()] 输出:YES，而输入([])，([)]都应该输出NO。

 【输入】
 第一行为一个整数n
 ，表示以下有多少个由括好组成的字符串。接下来的n
 行，每行都是一个由括号组成的长度不超过255
 的字符串。

 【输出】
 在输出文件中有n
 行，每行都是YES或NO。

 【输入样例】
 5
 {}{}<><>()()[][]
 {{}}{{}}<<>><<>>(())(())[[]][[]]
 {{}}{{}}<<>><<>>(())(())[[]][[]]
 {<>}{[]}<<<>><<>>>((<>))(())[[(<>)]][[]]
 ><}{{[]}<<<>><<>>>((<>))(())[[(<>)]][[]]
 【输出样例】
 YES
 YES
 YES
 YES
 NO
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++)
    {
        stack<int> stk;
        cin >> str;
        bool Match = true;
        for (auto c:str)
        {
            // 如果为左侧括号则入栈，入栈先判断顺序是否正确
            if (c == '<')
            {
                if(!stk.empty() && stk.top() < 1)
                {
                    cout << "NO" << endl;
                    Match = false;
                    break;
                }
                stk.push(1);
            }
            else if (c == '(')
            {
                if(!stk.empty() && stk.top() < 2)
                {
                    cout << "NO" << endl;
                    Match = false;
                    break;
                }
                stk.push(2);
            }
            else if (c == '[')
            {
                if(!stk.empty() && stk.top() < 4)
                {
                    cout << "NO" << endl;
                    Match = false;
                    break;
                }
                stk.push(4);
            }
            else if (c == '{')
            {
                if(!stk.empty() && stk.top() < 8)
                {
                    cout << "NO" << endl;
                    Match = false;
                    break;
                }
                stk.push(8);
            }
            else if (c == '>')
            {
                if(stk.empty() || stk.top() != 1)
                {
                    cout << "NO" << endl;
                    Match = false;
                    break;
                }
                else
                    stk.pop();
            }
            else if (c == ')')
            {
                if(stk.empty() || stk.top() != 2)
                {
                    cout << "NO" << endl;
                    Match = false;
                    break;
                }
                else
                    stk.pop();
            }
            else if (c == ']')
            {
                if(stk.empty() || stk.top() != 4)
                {
                    cout << "NO" << endl;
                    Match = false;
                    break;
                }
                else
                    stk.pop();
            }
            else if (c == '}')
            {
                if(stk.empty() || stk.top() != 8)
                {
                    cout << "NO" << endl;
                    Match = false;
                    break;
                }
                else
                    stk.pop();
            }
        }
        if (Match)
        {
            if (stk.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
