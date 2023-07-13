#include <bits/stdc++.h> 

bool cmp(pair<int , int>a , pair<int , int>b){
    return (double)a.second/a.first > (double)b.second/b.first;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(), items.end(), cmp);

    double ans = 0.0;

    for(int i=0;i<n;i++){
        if(items[i].first<=w){
            ans+= items[i].second;
            w-= items[i].first;
        }
        else {
            ans+= items[i].second*((double)w/items[i].first);
            break;
        }
    }
    return ans;
}