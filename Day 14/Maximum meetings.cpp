#include <bits/stdc++.h> 
bool cmp(pair<int , pair<int , int>>a , pair<int , pair<int , int >>b){
    if(a.second.first == b.second.first) return a.second.second<b.second.second;
    return a.second.first<b.second.first;
}


vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.

    // we have to use custom operator to sort start and end time .
    int n = start.size();
    vector<pair<int , pair<int , int>>>v;
    for(int i=0;i<n;i++) v.push_back({start[i], {end[i], i+1}});

    sort(v.begin(),v.end(), cmp);

    vector<int>res;
    res.push_back(v[0].second.second);
    int val = v[0].second.first;

    for(int i=0;i<v.size();i++){
        if(val<v[i].first){
            res.push_back(v[i].second.second);
            val = v[i].second.first;
        }
    }
    return res;

}