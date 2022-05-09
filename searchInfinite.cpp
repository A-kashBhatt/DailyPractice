/************************************************************

    Use get function that returns the value at index i
    in the infinite sorted binary array.

    get(i)
    {

    }


************************************************************/
#include <bits/stdc++.h>
using namespace std;
int arr[]{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int get(int i)
{
    return arr[i];
}

long long firstOne()
{
    long long int l = 2;

    while (get(l - 1) != 1)
    {
        l = l << 1;
    }

    long long s = 0, e = l - 1;
    while (e >= s)
    {
        long long int m = (s + e) / 2;
        if (get(m) >= 1)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    if (get(s) == 1)
    {
        return s;
    }
    else
    {
        return -1;
    }
}
int main()
{
    cout << firstOne();

    return 0;
}
