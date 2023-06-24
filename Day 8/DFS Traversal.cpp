
void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ls){
       vis[node]=1;
       ls.push_back(node);
       for(auto it:adj[node]){
           if(!vis[it]){
                dfs(it,adj,vis,ls);
           }
       }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
     // making graph - 
          vector<int>adj[V];
            for(int i=0;i<edges.size();++i){
             int u=edges[i][0];
             int v=edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
          }
// visited array - 
    vector<int>vis(V,0);
    vector<vector<int>>ans;
    for(int i=0;i<V;++i){
           if(!vis[i]){
               vector<int>ls;
               dfs(i,adj,vis,ls);
               ans.push_back(ls);
           }
      }
  return ans;
}