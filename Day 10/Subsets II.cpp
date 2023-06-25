#include <bits/stdc++.h> 

void solve(vector<int>&arr , int n , int idx , vector<vector<int>>&ans, vector<int>& ds){
    ans.push_back(ds);
    if(idx >= n) {
      return ;
    }
    for(int i=idx;i<n;i++){
        // duplicate handling 
        if(i>idx && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        solve(arr , n , i+1 , ans ,ds);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    if(n==0) return {};
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>ds;
    solve(arr , n , 0 , ans,ds);
    return ans;
}