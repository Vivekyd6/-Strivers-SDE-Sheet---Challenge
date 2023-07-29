
#include<bits/stdc++.h>


vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	// nlog n approach 
	// sort(arr.begin(),arr.end());
	// return {arr[k-1],arr[n-k]};

	// heap approach - 
    vector<int>ans(2);
	priority_queue<int , vector<int>, greater<int>>minHeap(arr.begin(), arr.end());
	while(k--) minHeap.pop();

	ans[0]=minHeap.top();

	priority_queue<int >maxHeap(arr.begin(),arr.end());

	while(k--) maxHeap.pop();
	ans[1]=maxHeap.top();

	return ans;
}