// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
// time complexity is linear and space complexity is constant

#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}

int largestAltitude(vector<int> &gain)
{
    int max = 0, curr = 0;
    int size = gain.size();
    for (int i = 0; i < size; i++)
    {
        curr += gain[i];
        if (curr > max)
        {
            max = curr;
        }
    }
    return max;
}
int main()
{
    vector<int> arr{2, 5, -6, 4, -8, -4, 10};
    cout << largestAltitude(arr);
}
