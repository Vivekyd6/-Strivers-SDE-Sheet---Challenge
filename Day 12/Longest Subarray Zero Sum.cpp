#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
   // bruteforce approach - generate all subarray sum and find max sum 

   // optimised using map
   int res = 0 , sum = 0;
   unordered_map<int , int >mp;
   for(int i=0;i<arr.size();i++){
       sum+=arr[i];
       if(sum == 0) res = i+1;
       else if(mp.find(sum)!=mp.end()) res = max(res , i-mp[sum]);
       else mp[sum]=i;
   }
   return res;

}