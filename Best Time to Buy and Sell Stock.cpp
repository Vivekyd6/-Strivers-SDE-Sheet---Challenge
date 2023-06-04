#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
     int minPrice = prices[0];
     int res = INT_MIN;

     for(auto i:prices){
         minPrice = min(minPrice , i);
         res = max(res , i-minPrice);
     }
     return res;
}