#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>res;

    res.push_back(intervals[0]);

    for(int i=1;i<n;i++){
        if(intervals[i][0]<=res.back()[1]){
            res.back()[1]=max(res.back()[1], intervals[i][1]);
        }
        else res.push_back(intervals[i]);
    }
    return res;
    
}
