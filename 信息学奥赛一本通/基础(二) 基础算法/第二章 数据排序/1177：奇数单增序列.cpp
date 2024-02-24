//
//  1177：奇数单增序列.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/20.
//

/*
 1177：奇数单增序列

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 55681     通过数: 28551
 【题目描述】
 给定一个长度为N（不大于500）的正整数序列，请将其中的所有奇数取出，并按升序输出。

 【输入】
 第1行为 N；

 第2行为 N 个正整数，其间用空格间隔。

 【输出】
 增序输出的奇数序列，数据之间以逗号间隔。数据保证至少有一个奇数。

 【输入样例】
 10
 1 3 2 6 5 4 9 8 7 10
 【输出样例】
 1,3,5,7,9
 */
#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, x;
    cin >> n;
    map<int, int> result;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x % 2 != 0)
            result[x]++;
    }
    for(auto num = result.begin(); num != result.end(); num++)
    {
        while(num->second--)
        {
            cout << num->first;
            if(num->second > 0 || next(num) != result.end())
            {
                cout << ",";
            }
        }
    }
    cout << endl;
    return 0;
}
