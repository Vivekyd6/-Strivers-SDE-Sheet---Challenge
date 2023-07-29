#include<bits/stdc++.h>

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans= "";
    sort(arr.begin(),arr.end());
    string s = arr[0];
    string l = arr[n-1];

    for(int i=0;i<s.size();i++){
        if(s[i]!=l[i]) break;
        ans = ans+s[i];
    }
    return ans;
}


