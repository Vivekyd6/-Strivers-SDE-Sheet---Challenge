vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int , int>m;
    for(auto i:arr) m[i]++;
    vector<int>ans;
    priority_queue<pair<int,int>>pq;
    for(auto i:m)
    {
        pq.push({i.second,i.first});
    }
    for(int i=1;i<=k;i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}