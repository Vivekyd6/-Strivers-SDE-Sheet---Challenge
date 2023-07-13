#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>adj[vertex];
    for(auto i:edges){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    for(int i=0;i<vertex;i++){
        sort(adj[i].begin(),adj[i].end());
    }

    vector<int>res;
    vector<int>vis(vertex,0);

    for(int i=0;i<vertex;i++){
        queue<int>q;
        if(!vis[i]){
            vis[i]=1;
            q.push(i);
            while(!q.empty()){
                auto tmp = q.front();
                q.pop();
                res.push_back(tmp);
                for(auto i:adj[tmp]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
        }
    }
    return res;
}