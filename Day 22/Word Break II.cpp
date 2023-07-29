#include <bits/stdc++.h> 
void solve(int idx,string t,string &s,unordered_map<string,int> &mp,vector<string> &ans)
{
    if(idx==s.length())
    {
        ans.push_back(t);
        return;
    }
    string a;
    for(int i=idx;i<s.length();i++)
    {
        a+=s[i];
        if (mp.find(a) != mp.end())
        {
          if (t.length() == 0)
            solve(i + 1, t + a, s, mp, ans);
          else
            solve(i + 1, t + " " + a, s, mp, ans);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &words)
{
    // Write your code here
    unordered_map<string,int> mp;
    for(auto it:words)
      mp[it]++;
    vector<string> ans;
    string t;
    solve(0,t,s,mp,ans);
    return ans;
}