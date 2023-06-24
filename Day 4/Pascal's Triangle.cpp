#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) {
     vector<vector<long long >>v;
    
      for(int i=0;i<n;i++){
        vector<long long >row(i+1,1);
        
        for(int j=1;j<i;j++)
          row[j]=v[i-1][j-1]+v[i-1][j];
      
       v.push_back(row);}
      return v;
}
