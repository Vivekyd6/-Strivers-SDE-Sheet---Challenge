#include <bits/stdc++.h> 

// based on pick or not pick condition of elements;--

void solve(int idx , int sum , vector<int>&num , vector<int>&res){
    // base case 
    if(idx == num.size()){
        res.push_back(sum);
        return;
    }
    // pick 
    solve(idx+1 , sum+num[idx], num , res);
    // not pick 
    solve(idx +1 , sum , num , res);

}
vector<int> subsetSum(vector<int> &num)
{

    // recursive solution 
    vector<int>res;
    solve(0 , 0 , num , res);
    sort(res.begin(),res.end());
    return res;
}