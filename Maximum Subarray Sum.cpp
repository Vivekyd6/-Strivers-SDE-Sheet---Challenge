#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    // kadanes algorithm
    long long ans = INT_MIN;
    long long csum = 0;
    for(int i=0;i<n;i++){
        csum+=arr[i];
        if(csum<0) csum = 0;
        ans = max(ans , csum);
    }
    return ans;
}