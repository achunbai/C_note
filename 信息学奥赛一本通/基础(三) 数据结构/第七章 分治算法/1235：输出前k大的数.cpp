//
//  1235：输出前k大的数.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/21.
//

/*
 1235：输出前k大的数

 时间限制: 1000 ms         内存限制: 65536 KB
 提交数: 31014     通过数: 9526
 【题目描述】
 给定一个数组，统计前k大的数并且把这k个数从大到小输出。

 【输入】
 第一行包含一个整数n，表示数组的大小。n < 100000。

 第二行包含n个整数，表示数组的元素，整数之间以一个空格分开。每个整数的绝对值不超过100000000。

 第三行包含一个整数k，k < n。

 【输出】
 从大到小输出前k大的数，每个数一行。

 【输入样例】
 10
 4 5 6 9 8 7 1 2 3 0
 5
 【输出样例】
 9
 8
 7
 6
 5
 */

#include <bits/stdc++.h>

using namespace std;
// TopK问题（海量数据的TopK）：（热搜，词条等）
/*
 1. O(nlogn)解法：直接快排
 2. O(nk)解法：类冒泡/类选择排序
 3. O(nlogk)解法：堆（解决TopK的好算法），并且可以处理动态数据
 4. O(n)解法：基于快排分治法（缺点不能处理动态数据）
 */


const int N = 1e5 + 10;

int nums[N];

inline int read() {     //快读
    char ch = '*';
    while (!isdigit(ch = getchar()));
    int num = ch - '0';
    while (isdigit(ch = getchar())) num = num * 10 + ch - '0';
    return num;
}

inline void write(int x) {     //快写
    if(x<0)
        putchar('-'), x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}

void bubbleSort_like(int* nums, int n, int k)
{
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
}

int main(int argc, const char * argv[])
{
    // 关闭cin/cout的输入输出同步，让其IO效率接近于scanf()/printf()
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    
    int n,k;
    // cin >> n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        // cin >> nums[i];
//        scanf("%d", &nums[i]);
        nums[i] = read();
    }
     sort(nums, nums + n, greater<int>());
    // cin >> k;
    
//    bubbleSort_like(nums, n, k);
    
     for(int i = 0; i < k; i++)
//    for(int i = n - 1; i >= n - k; i--)  // 从数组的末尾开始，输出最大的k个数
    {
        // cout << nums[i] << endl;
//        printf("%d\n", nums[i]);
        write(nums[i]);
        printf("\n");
    }
    return 0;
}
