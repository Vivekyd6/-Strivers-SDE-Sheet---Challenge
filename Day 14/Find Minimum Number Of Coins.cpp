#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    // greedy solution 
    vector<int>mp = {1000 , 500 , 100 , 50 , 20 , 10 , 5 , 2 ,1};
    int coin = 0;
    for(auto i:mp){
        while(amount>=i){
            amount -= i;
            coin++;
        }     
    }
    return coin;
}
