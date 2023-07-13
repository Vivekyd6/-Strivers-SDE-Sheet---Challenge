#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    int n = a.size(), m = b.size();
    int i=0, j=0;

    while(i<n || j<m){
        if(a[i]=='0') 
          while(i<n && a[i]=='0')i++;
        if(b[j]=='0')
          while(j<m && b[j]=='0') j++;

        long long n1 = 0, n2 = 0;

        while(i<n && a[i]!='.') n1 = (n1*10)+(a[i++]-'0');
        while(j<m && b[j]!='.') n2 = (n2*10)+(b[j++]-'0');

        if(n1>n2) return 1;
        else if(n1<n2) return -1;
        i++;
        j++;
    }
    return 0;
}