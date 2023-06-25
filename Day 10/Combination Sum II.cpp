#include<bits/stdc++.h>

void solve(int idx , int target, int n , vector<int>&ds , vector<vector<int>>& ans , vector<int>&arr){
	if(target == 0){
		ans.push_back(ds);
		return;
	}

	for(int i=idx ;i<n ;i++){
		if(i>idx && arr[i]==arr[i-1]) continue;
		if(arr[i]>target) break;
		ds.push_back(arr[i]);
		solve(i+1 , target-arr[i], n , ds , ans , arr);
		ds.pop_back();
	}
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<int>ds ;
	vector<vector<int>>ans ;
	solve(0 , target , n , ds , ans, arr);
	return ans;
}
