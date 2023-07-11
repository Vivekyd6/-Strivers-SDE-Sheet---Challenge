#include <bits/stdc++.h> 
bool isPalindrome(string s , int i , int j){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void solve(int idx , string &s , vector<string>&ds , vector<vector<string>>&ans){
    if(idx == s.size()){
        ans.push_back(ds);
        return;
    }

    for(int i=idx ;i<s.size();i++){
        if(isPalindrome(s, idx , i)){
            ds.push_back(s.substr(idx , i-idx+1));
            solve(i+1, s, ds, ans);
            ds.pop_back();
        }
    }
}


vector<vector<string>> partition(string &s) 
{
    // Write your code here.

    vector<vector<string>>ans;
    vector<string>ds;
    solve(0 , s , ds , ans);
    return ans;
}