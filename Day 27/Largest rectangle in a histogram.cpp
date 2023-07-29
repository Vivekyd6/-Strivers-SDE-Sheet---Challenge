#include<bits/stdc++.h>

vector<int> nse(vector<int> &heights, int n) {
  vector<int>res(n);
  stack<int>st;
  st.push(-1);

  for(int i=n-1;i>=0;i--){
    int curr = heights[i];
    while(st.top()!=-1 && heights[st.top()]>=curr) st.pop();
    res[i]=st.top();
    st.push(i);
  }

  return res;
}

vector<int>pse(vector<int>&heights , int n){
  vector<int>res(n);
  stack<int>st;
  st.push(-1);

  for(int i=0;i<n;i++){
    int curr = heights[i];
    while(st.top()!=-1 && heights[st.top()]>=curr) st.pop();
    res[i]=st.top();
    st.push(i);
  }

  return res;
}
int largestRectangle(vector<int> &arr) {
  // Write your code here.
  // 
  // int maxArea = 0;
  // int n = arr.size();
  // for (int i = 0; i < n; i++) {
  //   int minHeight = 1e5;
  //   for (int j = i; j < n; j++) {
  //     minHeight = min(minHeight, arr[j]);
  //     maxArea = max(maxArea, minHeight * (j - i + 1));
  //   }
  // }
  // return maxArea;

  // optimised approach using prevoius element and next greater elements =

  int n = arr.size();
  vector<int>next = nse(arr , n);
  vector<int>prev = pse(arr , n);

  int max_area = INT_MIN;
  for(int i=0;i<n;i++){
    int l = arr[i];
    if(next[i]==-1) next[i]=n;
    int h = next[i]-prev[i]-1;

    int currArea = l*h;
    max_area = max(currArea , max_area);
  }

  return max_area;
}