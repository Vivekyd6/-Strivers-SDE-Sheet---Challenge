#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        auto curr = arr[i];
        while(!st.empty() && st.top()<=curr) st.pop();
        if(st.empty()) arr[i]=-1;
        else arr[i]=st.top();

        st.push(curr);
    }
    return arr;
}