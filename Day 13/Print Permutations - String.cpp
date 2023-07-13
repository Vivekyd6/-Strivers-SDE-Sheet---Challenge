#include <bits/stdc++.h> 
void solve(string &s , int idx , vector<string>&ans){
    if(idx == s.size()){
        ans.push_back(s);
        return ;
    }

    for(int i=idx;i<s.size();i++){
        swap(s[i],s[idx]);
        solve(s , idx+1 , ans);
        swap(s[i],s[idx]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    solve(s , 0 , ans);
    return ans;
    
}