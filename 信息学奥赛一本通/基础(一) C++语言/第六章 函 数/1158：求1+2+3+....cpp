#include <iostream>

using namespace std;

int getResult(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n + getResult(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << getResult(n) << endl;
    return 0;
}