// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
#include <bits/stdc++.h>
using namespace std;

// i know mashed up ,but modify it and also solve it using recursion some time later with //better code and complexity

int binarySearch(vector<int> arr, int s, int e, int key)
{
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (arr[m] == key)
        {
            return m;
        }
        else if (arr[m] > key)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return -1;
}
int pivot(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1;
    while (e >= s)
    {
        int m = (s + e) / 2;
        if (m < e && nums[m] > nums[m + 1])
        {
            return m;
        }
        if (m > 0 && nums[m - 1] > nums[m])
        {
            return (m - 1);
        }
        if (nums[m] > nums[0])
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int size = nums.size();
    int p = pivot(nums);
    if (p == -1)
    {
        return binarySearch(nums, 0, size - 1, target);
    }
    else
    {
        if (nums[p] == target)
        {
            return p;
        }
        else
        {
            if (target > nums[0])
            {
                // apply binary search in 0 to p-1
                return binarySearch(nums, 0, p - 1, target);
            }
            else if (target == nums[0])
            {
                return 0;
            }
            else
            {
                // apply binary search in p+1 to e
                return binarySearch(nums, p + 1, size - 1, target);
            }
        }
    }
}
