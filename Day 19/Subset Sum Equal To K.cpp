#include <bits/stdc++.h>
bool solve(int n , int k , vector<int>&arr , int idx , vector<vector<int>>&dp) {
    // base case 
    if(k==0) return true;
    if(idx == n) return false;

    if(dp[idx][k]!=-1) return dp[idx][k];

    bool nottake = solve(n , k , arr , idx+1 , dp);
    bool take = 0;
    if(arr[idx]<=k) take = solve( n , k-arr[idx], arr , idx+1 , dp);

    return dp[idx][k]=take || nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n , vector<int>(k+1,-1));
    return solve(n , k , arr , 0 , dp);
}