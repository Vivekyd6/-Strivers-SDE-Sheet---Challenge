#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code here
        int ans=0;
        unordered_set<char>set;
        int i=0;
        int j=0;
        int n=s.size();
        while(i<n && j<n){
            if(set.find(s[j])==set.end()){
                set.insert(s[j++]);
                ans=max(ans,j-i);
            }
            else
                set.erase(s[i++]);
        }
        return ans;

}