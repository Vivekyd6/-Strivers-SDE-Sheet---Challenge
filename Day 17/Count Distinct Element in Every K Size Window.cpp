#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	vector<int>ans;
    unordered_map<int, int>mp;
    int n = arr.size();
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        if (i >= k - 1) {
          ans.push_back(mp.size());
          mp[arr[i - k + 1]]--;
          if (mp[arr[i - k + 1]] == 0)
            mp.erase(arr[i - k + 1]);
        }
    }
    return ans;
}
