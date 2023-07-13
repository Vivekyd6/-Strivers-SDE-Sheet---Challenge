#include <bits/stdc++.h>

long long int solve(int x,int n,int m){
        if(n==0) return 1;
        long long int ans = solve(x,n/2,m);
        if(n<0){
            if(n&1){
                return ((ans * ans) /x)%m;
            } else {
                return (ans * ans)%m;
            }
        } else {
            if(n&1){ 
                return (((ans * ans)%m) * x)%m;
            } else {
                return (ans * ans)%m;
            }
        }
}

int modularExponentiation(int x, int n, int m) {
    return solve(x,n,m)%m;
}