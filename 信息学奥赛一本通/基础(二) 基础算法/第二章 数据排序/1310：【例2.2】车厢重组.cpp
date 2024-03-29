//
//  1310：【例2.2】车厢重组.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/21.
//

/*
 1310：【例2.2】车厢重组

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 46954     通过数: 28230
 【题目描述】
 在一个旧式的火车站旁边有一座桥，其桥面可以绕河中心的桥墩水平旋转。一个车站的职工发现桥的长度最多能容纳两节车厢，如果将桥旋转180度，则可以把相邻两节车厢的位置交换，用这种方法可以重新排列车厢的顺序。于是他就负责用这座桥将进站的车厢按车厢号从小到大排列。他退休后，火车站决定将这一工作自动化，其中一项重要的工作是编一个程序，输入初始的车厢顺序，计算最少用多少步就能将车厢排序。

 【输入】
 有两行数据，第一行是车厢总数N（不大于10000），第二行是N个不同的数表示初始的车厢顺序。

 【输出】
 一个数据，是最少的旋转次数。

 【输入样例】
 4
 4 3 2 1
 【输出样例】
 6
 */

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e3 + 10;

int bubbleSort(vector<int>& nums)
{
    int cnt = 0, len = (int)nums.size();
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len - i - 1; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, const char * argv[])
{
    int n, x;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        nums.emplace_back(x);
    }
    int result = bubbleSort(nums);
    cout << result << endl;
    return 0;
}
