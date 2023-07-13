#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    // approach 1 - sorting 

    if(str1.length()!=str2.length()) return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1==str2;
}