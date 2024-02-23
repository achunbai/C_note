//
//  1282：最大子矩阵.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/2/18.
//

/*
 1282：最大子矩阵

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 14833     通过数: 7284
 【题目描述】
 已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 × 1)子矩阵。

 比如，如下4 × 4的矩阵

 0  -2 -7  0
 9  2 -6  2
 -4  1 -4  1
 -1  8  0 -2
 的最大子矩阵是

  9 2
 -4 1
 -1 8
 这个子矩阵的大小是15。

 【输入】
 输入是一个N×N
 的矩阵。输入的第一行给出N(0<N≤100)
 。再后面的若干行中，依次(首先从左到右给出第一行的N
 个整数，再从左到右给出第二行的N
 个整数……)给出矩阵中的N2
 个整数，整数之间由空白字符分隔(空格或者空行)。已知矩阵中整数的范围都在[−127,127]
 。

 【输出】
 输出最大子矩阵的大小。

 【输入样例】
 4
 0 -2 -7  0
 9  2 -6  2
 -4  1 -4  1
 -1  8  0 -2
 【输出样例】
 15
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <climits>

/*
 本题思路：
    转换为固定区间所有矩阵中的最大子矩阵
    枚举从i1行到i2行之间的最大子矩阵
 
 如何处理行内最大子矩阵：
    利用最大子段和带入求解
        思路：
            二维变一维
        Step1：
            将每一列中row1行到row2行所有的元素加起来，压维，二维变一维，得到了最大子段和
                注意：
                    利用前缀和进行累加，不然从头开始遍历过于浪费时间，时间复杂度特别高，这样优化就变得没有意义。
        Step2：
            在一维的最大子段和中求其中的最大子段，可以得到从row1行到row2行的最大子矩阵（纵向压缩得到前缀和，横向求最大子段和）
            
            即压缩维度 -> 一维dp即可实现求row1行到row2行的最大子矩阵
        
        Step3：
            将局部拓展为全局，遍历所有的row1和row2行，得到全局的最大子矩阵
 
 */

using namespace std;

const int N = 1e2 + 10;

// presum[i][j] 第j列的前i行和
int a[N][N], compressed[N], dp[N], presum[N][N];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            // 从第一行开始，求前缀和，该行元素和上一行元素所形成的矩阵相加
            // 这样进行第一行到第i行的前缀和，实现压缩维度
            // 即为求第j列的前i行和
            presum[i][j] = presum[i - 1][j] + a[i][j];
        }
    }
    
    // 初始化全局最大值
    int max_val = INT_MIN;
    
    // 枚举所有的row1和row2
    for(int row1 = 1; row1 <= n; row1++)
    {
        // 从row1行开始往下遍历找到row2行，取row2行和row1行之间的行，注意row2从row1开始遍历，而不是第一行开始遍历
        for(int row2 = row1; row2 <= n; row2++)
        {
            // 枚举row1到row2行所有的列，求累加和
            for(int i = 1; i <= n; i++)
            {
                // 求第j列row1行到row2行的累加和
                // 注意row1需要-1，不然得不到正确的前缀和，比如需要求第一行的和，这样row2和row1相等，和为0，显然不正确
                compressed[i] = presum[row2][i] - presum[row1 - 1][i];
            }
            // 针对compressed数组求最大子段和，其实就是针对row1行到row2行求最大子矩阵
            // 别忘了从1开始结尾需要=n，不然会出事
            for(int i = 1; i <= n; i++)
            {
                // 决策，如果前面的子段和对当前的有负面影响，那就不从前面的状态转移，直接取自身
                dp[i] = max(dp[i - 1] + compressed[i], compressed[i]);
                // 记录全局最大子段和
                max_val = max(max_val, dp[i]);
            }
        }
    }
    
    cout << max_val << endl;
    return 0;
}
