#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    // bruteforce approach - 
    // take a vector , add all elements  and then sort each one 

//     vector<int>ans;
//     for(auto v:kArrays){
//         for(auto i:v) ans.push_back(i);
//     }

//     sort(ans.begin(), ans.end());
//     return ans;

// optimised using minheap;

   vector<int>ans;
   
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > >pq;
    for(int i=0;i<k;i++){
        pq.push({kArrays[i][0],{i,0}});
    }

    while(!pq.empty()){
        pair<int , pair<int , int>>curr = pq.top();
        pq.pop();

        int a = curr.second.first;
        int b = curr.second.second;

        ans.push_back(curr.first);

        if(b+1<kArrays[a].size())
         pq.push({kArrays[a][b+1], {a , b+1}});
    }

    return ans;

}
