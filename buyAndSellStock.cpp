// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Having quadratic time complexity

//     int maxProfit(vector<int>& prices) {
//         int size=prices.size(),max=0;
//         for(int i=0;i<size-1;i++){
//             for(int j=i+1;j<size;j++){
//                 if(prices[j]-prices[i]>max){
//                     max=(prices[j]-prices[i]);
//                 }
//             }
//         }
//         return max;
//     }

// Having linear time complexity

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int min = prices[0], maxP = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] - min > maxP)
        {
            maxP = prices[i] - min;
        }
        if (prices[i] < min)
        {
            min = prices[i];
        }
    }
    return maxP;
}

int main()
{
    vector<int> arr{3, 6, 7, 4, 2, 14, 15, 10, 8, 4};
    int max = maxProfit(arr);
    cout << max << endl;

    return 0;
}
