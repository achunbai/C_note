//
//  1356：计算(calc).cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/12.
//

/*
 1356：计算(calc)

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 15781     通过数: 6825
 【题目描述】
 小明在你的帮助下，破密了Ferrari设的密码门，正要往前走，突然又出现了一个密码门，门上有一个算式，其中只有“(”，“)”，“0-9”，“+”，“-”，“*”，“/”，“^”，求出的值就是密码。小明数学学得不好，还需你帮他的忙。(“/”用整数除法)

 【输入】
 共1行，为一个算式。

 【输出】
 共1行，就是密码。

 【输入样例】
 1+(3+2)*(7^2+6*9)/(2)
 【输出样例】
 258
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
    str.push_back('+');
    char sign = '+';
    for (auto c:str)
    {
        // 用isdigit判断是否为数字，isnumber是非标准函数
        if (isdigit(c))
            tmp = tmp * 10 + c - '0';
        else if (sign == '+')
        {
            stk.push(tmp);
            sign = c;
            tmp = 0;
        }
        else if (sign == '-')
        {
            stk.push(-tmp);
            sign = c;
            tmp = 0;
        }
        else if (sign == '*')
        {
            stk.top() *= tmp;
            tmp = 0;
            sign = c;
        }
        else if (sign == '/')
        {
            stk.top() /= tmp;
            tmp = 0;
            sign = c;
        }
        else if (sign == '^')
        {
            stk.top() = pow(stk.top(), tmp);
            tmp = 0;
            sign = c;
        }
    }
    while (!stk.empty())
    {
        sum += stk.top();
        stk.pop();
    }
    str.pop_back();
    return sum;
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
