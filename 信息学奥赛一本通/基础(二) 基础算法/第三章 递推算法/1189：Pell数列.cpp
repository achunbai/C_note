//
//  1189：Pell数列.cpp
//  algorithm
//
//  Created by Yamaxanadu Shikieiki on 2024/1/22.
//

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int pell[N] = {0, 1, 2};

void getPell()
{
    for(int i = 3; i < N; i++)
        pell[i] = (pell[i - 1]%32767 + pell[i - 1]%32767 + pell[i - 2]%32767)%32767;
}

int main(int argc, const char * argv[])
{
    int n, x;
    cin >> n;
    getPell();
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        cout << pell[x] << endl;;
    }
    return 0;
}
