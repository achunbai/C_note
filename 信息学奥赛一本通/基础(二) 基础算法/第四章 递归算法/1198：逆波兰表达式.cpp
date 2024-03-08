//
//  1198：逆波兰表达式.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/25.
//

/*
 1198：逆波兰表达式

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 21680     通过数: 13463
 【题目描述】
 逆波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的逆波兰表示法为+ 2 3。逆波兰表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，例如(2 + 3) * 4的逆波兰表示法为* + 2 3 4。本题求解逆波兰表达式的值，其中运算符包括+ - * /四个。

 【输入】
 输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。

 【输出】
 输出为一行，表达式的值。

 可直接用printf("%f\n", v)输出表达式的值v。

 【输入样例】
 * + 11.0 12.0 + 24.0 35.0
 【输出样例】
 1357.000000
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

double calc()
{
    string s;
    cin >> s;
    if(s[0] == '+')
        return calc() + calc();
    if(s[0] == '-')
        return calc() - calc();
    if(s[0] == '*')
        return calc() * calc();
    if(s[0] == '/')
        return calc() / calc();
    return stod(s);
}

// * + 1 2 + 4 5
// 1.calc()   *    return calc()==3 * calc()==9  =27
// 2.calc()   +    return calc()==4 + calc()==5  =9
// 3.calc()   5    return 5
// 3.calc()   4    return 4
// 2.calc()   +    return calc()==1 + calc()==2  =3
// 3.calc()   2    return 2
// 3.calc()   1    return 1

int main(int argc, const char * argv[])
{
    printf("%lf\n", calc());
    return 0;
}
