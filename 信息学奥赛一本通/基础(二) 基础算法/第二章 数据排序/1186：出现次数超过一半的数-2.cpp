//
//  1186：出现次数超过一半的数-2.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/22.
//

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;
int cnt[N];

int main(int argc, const char * argv[])
{
    int n, x;
    cin >> n;
    int opt = (n + 1) / 2;
//    int result = -1000;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        cnt[x + 50]++;
//        if(cnt[x + 50] >= opt)
//            result = x + 50;
    }
    for(int i = 0; i < 101; i++)
    {
        if(cnt[i] >= opt)
        {
            cout << i - 50 << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}
