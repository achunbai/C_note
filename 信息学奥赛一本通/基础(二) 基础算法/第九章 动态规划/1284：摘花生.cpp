//
//  1284：摘花生.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/19.
//

/*
 1284：摘花生

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 15776     通过数: 10299
 【题目描述】
 Hello Kitty想摘点花生送给她喜欢的米老鼠。她来到一片有网格状道路的矩形花生地(如下图)，从西北角进去，东南角出来。地里每个道路的交叉点上都有种着一株花生苗，上面有若干颗花生，经过一株花生苗就能摘走该它上面所有的花生。Hello Kitty只能向东或向南走，不能向西或向北走。问Hello Kitty最多能够摘到多少颗花生。



 【输入】
 第一行是一个整数T
 ，代表一共有多少组数据。1≤T≤100
 接下来是T
 组数据。

 每组数据的第一行是两个整数，分别代表花生苗的行数R和列数 C(1≤R,C≤100)
 每组数据的接下来R行数据，从北向南依次描述每行花生苗的情况。每行数据有C
 个整数，按从西向东的顺序描述了该行每株花生苗上的花生数目M(0≤M≤1000)
 。

 【输出】
 对每组输入数据，输出一行，内容为Hello Kitty能摘到得最多的花生颗数。

 【输入样例】
 2
 2 2
 1 1
 3 4
 2 3
 2 3 4
 1 6 5
 【输出样例】
 8
 16
 */

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
 本题有点像过河卒，只能向下或者向右走，需要先处理第一行和第一列
 状态：
    dp[i][j]表示从原点(1, 1)走到(i, j)所摘走的花生总数
 状态转移方程：
    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + field[i][j]
 */

const int N = 1e3 + 10;

int field[N][N], dp[N][N];

int main(int argc, const char * argv[])
{
    int n, row, col;
    cin >> n;
    for(int t = 0; t < n; t++)
    {
        cin >> row >> col;
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                cin >> field[i][j];
        
        // 处理第一行
        for(int i = 1; i <= col; i++)
            dp[1][i] = dp[1][i - 1] + field[1][i];
        // 处理第一列
        for(int i = 1; i <= row; i++)
            dp[i][1] = dp[i - 1][1] + field[i][1];
        
        // 决策，从第二行第二列开始，第一列和第一行已经处理过了
        for(int i = 2; i <= row; i++)
            for(int j = 2; j <= col; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + field[i][j];
        
        // debug 输出一下dp结果
//        cout << "dp" << t << endl;
//        for(int i = 1; i <= row; i++)
//        {
//            for(int j = 1; j <= col; j++)
//                cout << dp[i][j] << "\t";
//            cout << endl;
//        }
        
        cout << dp[row][col] << endl;
    }
    return 0;
}
