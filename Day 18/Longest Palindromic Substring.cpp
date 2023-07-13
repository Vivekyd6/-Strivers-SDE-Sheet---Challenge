
string solve(string s , int l , int r){
    while(l>=0 && r<s.size()){
        if(s[l]!=s[r]) break;
        l--;
        r++;
    }
    return s.substr(l+1 , r-l-1);
}
string longestPalinSubstring(string s)
{
    // optimised approach - expand from center approach 
    string res;
    int n = s.size();
    for(int i=0;i<n;i++){
        string odd = solve(s , i , i);
        string even = solve(s , i , i+1);
        if(odd.size()>res.size()) res = odd;
        if(even.size()>res.size()) res = even;
    }
    return res;

}