#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.

	priority_queue<int> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(a[i]+b[j]);
        }   
    }
    vector<int> ans;
    while(k--){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}