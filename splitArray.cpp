// Given an integer array A of size N, check if the input array can be splitted in two parts such that -
// - Sum of both parts is equal
// - All elements in the input, which are divisible by 5 should be in same group.
// - All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
// - Elements which are neither divisible by 5 nor by 3, can be put in any group.
// Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
// Return true, if array can be split according to the above rules, else return false.

// Constraints :
// 1 <= N <= 50

#include <bits/stdc++.h>
using namespace std;

bool helper(int arr[], int l, int sum, int target)
{
    if (l == 0)
    {
        return (sum == target);
    }
    return ((helper(arr + 1, l - 1, sum + arr[0], target)) || (helper(arr + 1, l - 1, sum, target)));
}

bool splitArray(int *input, int size)
{

    int sum = 0, sum1 = 0, sum2 = 0, l = 0;
    int arr[51];
    for (int i = 0; i < size; i++)
    {
        sum += input[i];
        if (input[i] % 5 == 0)
        {
            sum1 += input[i];
        }
        else if ((input[i] % 3) == 0 && (input[i] % 5) != 0)
        {
            sum2 += input[i];
        }
        else
        {

            arr[l++] = input[i];
        }
    }
    if (sum % 2 != 0)
    {
        return false;
    }

    int rem = sum - sum1 - sum2;

    if (sum1 > sum2 + rem || sum2 > sum1 + rem)
    {
        return false;
    }

    if (sum1 == (sum / 2))
    {
        return true;
    }
    int dis = (rem - (abs(sum1 - sum2)));
    if (dis % 2 != 0)
    {
        return false;
    }
    int target = (rem - (abs(sum1 - sum2))) / 2;

    return helper(arr, l, 0, target);

    // for(int i=0;i<l;i++){
    //     int sum=0;
    //     for(int j=i;j<l;j++){
    //         sum+=arr[j];
    //         if(sum==target){
    //             return true;
    //         }
    //     }
    // }
    //  return false;
}
