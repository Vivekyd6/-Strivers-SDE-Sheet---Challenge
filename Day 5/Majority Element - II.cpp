#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
    // extension of mvp algorithms 
        int num1=-1;
        int num2=-1;
        int cnt1 = 0;
        int cnt2=0;
        for(auto i:nums){
          if(i==num1) cnt1++;
          else if(i==num2) cnt2++;
          else if(cnt1==0) num1=i,cnt1=1;
          else if(cnt2==0) num2=i,cnt2=1;
          else{
            cnt1--;
            cnt2--;
          }
        }
        int n = nums.size();
        int ans1=0;
        int ans2=0;
        for(auto i:nums){
          if(i==num1) ans1++;
          else if(i==num2) ans2++;
        }

        vector<int>res;
        if(ans1>n/3) res.push_back(num1);
        if(ans2>n/3) res.push_back(num2);
      return res;
}