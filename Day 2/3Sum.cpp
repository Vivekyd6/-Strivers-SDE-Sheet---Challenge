#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	// Write your code here.
    

    // Modified two pointer approach ( extension of two sum problems).
	 vector<vector<int>>res;

	 sort(nums.begin(), nums.end());

	 for(int i=0;i<n-2;i++){
		 int l = i+1;
		 int r = n-1;

		 int target = K-nums[i];
		 while(l<r){
           int sum = nums[l]+nums[r];
		   if(sum==target) {
			   vector<int>ans;
			   int x = nums[l], y = nums[r];
			   ans.push_back(nums[i]);
			   ans.push_back(nums[l]);
			   ans.push_back(nums[r]);
			   res.push_back(ans);
			while(l<r && nums[l]==x)l++;
		    while(l<r && nums[r]==y)r--;
		   }
		   else if(sum>target) r--;
		   else l++;
		 }
		 while(i+1<n && nums[i]==nums[i+1]) i++;
	 }
	 return res;
}