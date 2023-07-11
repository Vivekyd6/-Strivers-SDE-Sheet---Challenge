#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    // nlogn approach - 
    // sort(arr.begin(),arr.end());
    // int cnt=1;
    int res  =1 ;
    // for(int i=1;i<n;i++){
    //     // avoiding duplicate
    //     if(i>0 && arr[i]==arr[i-1]) continue;

    //     if(arr[i]==arr[i-1]+1) cnt++;
    //     else cnt = 1;

    //     res = max(res , cnt);
    // }
    // return res;

    // hash set approach 

    unordered_set<int>st(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
      if (st.find(arr[i] - 1) == st.end()) {
        int val = arr[i];
        while (st.find(val) != st.end())
          val++;

        res = max(res, val - arr[i]);
      }
    }
    return res;
}