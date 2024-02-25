//
//  1184：明明的随机数-2.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/22.
//

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int cnt[N];

int main(int argc, const char * argv[])
{
    int n, x, max_val = 0, min_val = 1001, cnt_sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x > max_val)
            max_val = x;
        if (x < min_val)
            min_val = x;
        if (!cnt[x])
            cnt_sum++;
        cnt[x]++;
    }
    cout << cnt_sum << endl;
    for(int i = min_val; i <= max_val; i++)
    {
        if(cnt[i])
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
