//
//  1205：汉诺塔问题.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/25.
//

// #include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

const int N = 1e3 + 10;

void Hanoi(int n, char a, char b, char c)
{
    if(n == 0)
        return;
    // a移动到b，借助c
    Hanoi(n - 1, a, c, b);
    printf("%c->%lld->%c\n", a, n, b);
    // c移动到a，借助b
    Hanoi(n - 1, c, b, a);
}

signed main(signed argc, const char * argv[])
{
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    Hanoi(n, a, b, c);
    return 0;
}
