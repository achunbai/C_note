//
//  1185：单词排序.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/19.
//

/*
 1185：单词排序

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 30168     通过数: 15399
 【题目描述】
 输入一行单词序列，相邻单词之间由1个或多个空格间隔，请按照字典序输出这些单词，要求重复的单词只输出一次。（区分大小写）

 【输入】
 一行单词序列，最少1个单词，最多100个单词，每个单词长度不超过50，单词之间用至少1个空格间隔。数据不含除字母、空格外的其他字符。

 【输出】
 按字典序输出这些单词，重复的单词只输出一次。

 【输入样例】
 She  wants  to go to Peking University to study  Chinese
 【输出样例】
 Chinese
 Peking
 She
 University
 go
 study
 to
 wants
 */

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// map
int main(int argc, const char * argv[])
{
    string s;
    map<string, int> mp;
    while(cin >> s)
    {
        mp[s]++;
    }
    for(auto c:mp)
    {
        cout << c.first << endl;
    }
    return 0;
}

// set
/*
 int main(int argc, const char * argv[])
 {
     set<string> st;
     string s;
     while(cin >> s)
     {
         st.insert(s);
     }
     for(auto c:st)
     {
         cout << c << endl;
     }
     return 0;
 }
 */

