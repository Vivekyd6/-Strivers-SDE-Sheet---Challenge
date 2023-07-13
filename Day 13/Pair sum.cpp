#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // // Write your code here.
   // sort(arr.begin(),arr.end());

   // int i=0;
   // int j = arr.size()-1;
   // vector<vector<int>>res;

   // while(i<=j){
   //    int sum = arr[i]+arr[j];
   //    if(sum == s){
   //        vector<int>ans(2);
   //        ans[0]= arr[i];
   //        ans[1]=arr[j];
   //        res.push_back(ans);
   //    }
   //    else if(sum>s) j--;
   //    else i++;
   // }

   // return res;
    vector<vector<int>> res;
    // unordered_set<int> seen;
    for (int i = 0; i < arr.size(); i++) {
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==s){
                    vector<int>ans;
                    ans.push_back(min(arr[i],arr[j]));
                    ans.push_back(max(arr[i],arr[j]));
                    res.push_back(ans);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}