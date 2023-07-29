#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
     int n = p.size();
     int m = s.size();
     for(int i=0;i<m-n+1;i++){
         if(s.substr(i , n)==p) return true;
     }
     return false;
}