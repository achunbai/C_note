//
//  1358：中缀表达式值(expr).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/13.
//

/*
 1358：中缀表达式值(expr)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 12163     通过数: 4268
 【题目描述】
 输入一个中缀表达式（由0-9组成的运算数、加+减-乘*除/四种运算符、左右小括号组成。注意“-”也可作为负数的标志，表达式以“@”作为结束符），判断表达式是否合法，如果不合法，请输出“NO”；否则请把表达式转换成后缀形式，再求出后缀表达式的值并输出。

 注意：必须用栈操作，不能直接输出表达式的值。

 【输入】
 一行为一个以@结束的字符串。

 【输出】
 如果表达式不合法，请输出“NO”，要求大写。

 如果表达式合法，请输出计算结果。

 【输入样例】
 1+2*8-9@
 【输出样例】
 8
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

int GetSum(string& str)
{
    stack<int> stk;
    // 入栈第一个为正数
    int tmp = 0, sum = 0;
//    cout << str << endl;
    str.push_back('+');
//    cout << str << endl;
    char sign = '+';
    bool neg = false;
    for (int i = 0; i < str.length(); i++)
    {
        // 本题负号比较复杂，他有两种意思，第一种是运算符，表示减号
        // 特判一下是否为负号，是符号的话neg标记为true
        if (str[i] == '-')
        {
            if(i == 0 || !isdigit(str[i - 1]))
            {
                neg = true;
//                cout << "true" << endl;
                continue;
            }
        }
//        cout << str[i] << endl;
        // 用isdigit判断是否为数字，isnumber是非标准函数
        if (isdigit(str[i]))
            tmp = tmp * 10 + str[i] - '0';
        else if (sign == '+')
        {
            // 注意三目运算符别用反了 (条件) ? (为真时语句) : (为假时语句)
            stk.push(neg ? -tmp : tmp);
            sign = str[i];
            tmp = 0;
            neg = false;
        }
        else if (sign == '-')
        {
            stk.push(-tmp);
            sign = str[i];
            tmp = 0;
            neg = false;
        }
        else if (sign == '*')
        {
            stk.top() *= neg ? -tmp : tmp;
            tmp = 0;
            sign = str[i];
            neg = false;
        }
        else if (sign == '/')
        {
            stk.top() /= neg ? -tmp : tmp;
            tmp = 0;
            sign = str[i];
            neg = false;
        }
        else if (sign == '^')
        {
            stk.top() = pow(stk.top(), neg ? -tmp : tmp);
            tmp = 0;
            sign = str[i];
            neg = false;
        }
    }
    while (!stk.empty())
    {
        sum += stk.top();
//        cout << stk.top() << " " << "+";
        stk.pop();
    }
//    cout << endl;
    str.pop_back();
    return sum;
}

bool isLegal(string& str)
{
    stack<char> stk;
    for(int i = 0; i < str.size(); i++)
    {
        if (i > 0 && (str[i] == '+' || str[i] == '*' || str[i] == '/') && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/'))
            return 0;
        switch (str[i])
        {
            case '(':
            case '[':
            case '{':
                stk.push(str[i]);
                break;
            case ')':
                if (stk.empty())
                {
                    return 0;
                }
                else if (stk.top() != '(')
                {
                    return 0;
                }
                else
                    stk.pop();
                break;
            case ']':
                if (stk.empty())
                {
                    return 0;
                }
                else if (stk.top() != '[')
                {
                    return 0;
                }
                else
                    stk.pop();
                break;
            case '}':
                if (stk.empty())
                {
                    return 0;
                }
                else if (stk.top() != '{')
                {
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
        return 1;
    else
        return 0;
}

// ver2.0 不修改原串的版本，归递处理括号
int calc(const string& str)
{
    stack<int> cal;
    int num = 0;
    // 默认运算符为+，第一个数字肯定要入栈
    char sign = '+';
    for(int i = 0; i <= str.length(); i++)
    {
        if(isdigit(str[i]))
            num = num * 10 + str[i] - '0';
        else
        {
            // 归递处理括号匹配
            if(str[i] == '(')
            {
                int start = i, cnt = 1;
                i++;
                while (cnt > 0)
                {
                    if(str[i] == '(')
                        cnt++;
                    else if(str[i] == ')')
                        cnt--;
                    i++;
                }
                // 这里为右值，故calc的参数需要加const，变成万能引用
//                cout << str.substr(start + 1, i - start - 2) << endl;
                num = calc(str.substr(start + 1, i - start - 2));
//                cout << num << endl;
            }
            if(sign == '+')
                cal.push(num);
            if(sign == '-')
                cal.push(-num);
            if(sign == '*')
                cal.top() *= num;
            if(sign == '/')
                cal.top() /= num;
            if(sign == '^')
                cal.top() = pow(cal.top(), num);
            num = 0;
            sign = str[i];
        }
    }
    int ans = 0;
    while (!cal.empty())
    {
        ans += cal.top();
        cal.pop();
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    // 优先级
    // 括号内的 -> 乘方 -> 乘除 -> 加减
    string str, subcal;
    cin >> str;
    size_t start, end;
    int cal_tmp;
    // 删除结尾的@
    str.pop_back();
//    cout << str << endl;
    while((start = str.find("--")) != std::string::npos)
    {
        str.replace(start, 2 , "+");
    }
    while((start = str.find("-+")) != std::string::npos)
    {
        str.replace(start, 2 , "-");
    }
    while((start = str.find("+-")) != std::string::npos)
    {
        str.replace(start, 2 , "-");
    }
    // 检查合法性
    if(!isLegal(str))
    {
        cout << "NO" << endl;
        return 0;
    }
    // 先算小括号内的
    // 截取小括号内的字符串，调用函数计算没有括号的表达式，然后将计算结果插回到原字符串
    // std::string::npos表示没找到，其实判断是否小于str.size()就行了
    // 需要考虑括号嵌套的情况
//    while ((start = str.find_first_of('(', 0)) != std::string::npos)
//    {
//        end = str.find_first_of(')', start + 1);
//        size_t start_tmp;
//        if (end != std::string::npos)
//        {
//            while ((start_tmp = str.find_first_of('(', start + 1)) != std::string::npos && start_tmp < end)
//            {
//                start = start_tmp;
//                // 如果不继续查找左右括号之间的右括号，会导致BUG
//                /*
//                 1+(3+2)*(7^2+6*9)/(2)
//
//                 7^2+6*9)/(2)
//                 1+(3+2)*103
//                 3+2
//                 1+5*103
//                 */
//                end = str.find_first_of(')', start + 1);
//            }
//        }
//        else
//            break;
//        // 截取带括号的子字符串
//        subcal = str.substr(start + 1, end - start - 1);
////        cout << subcal << endl;
//        // 计算子字符串的值
//        cal_tmp = GetSum(subcal);
//        // 删除带括号字段
//        str.erase(start, end - start + 1);
//        // to_string可以将数字转为字符串
//        // 将计算结果回插字符串内
//        str.insert(start, to_string(cal_tmp));
////        cout << str << endl;
//    }
//    // 此时应该没有了带括号需要先计算的内容，再调用一遍函数计算就完事了
//    cout << GetSum(str) << endl;
    cout << calc(str) << endl;
    return 0;
}
