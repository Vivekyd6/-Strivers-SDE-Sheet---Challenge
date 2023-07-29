
// int fact [9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320};
    

string kthPermutation(int n, int k) {
    // Write your code here.
        string ans = "";
        for(int i=1;i<=n;i++)
            ans+=to_string(i);
        
        
        vector<int>fact(n+1);
        fact[0]=1;
        for(int i=1;i<n;i++)
            fact[i]=fact[i-1]*i;
        string res = "";
        k--;
        for(int i=n-1;i>=0;i--){
            int idx = (k)/(fact[i]);
            k%=fact[i];
            res+=ans[idx];
            ans.erase(ans.begin()+idx);
        }
        
        return res;
}
