bool isSafe(int u, vector<vector<int>> mat, int c, int V, int m, vector<int>& color){
    color[u] = c;
    for(int i=0; i<V; i++){
        if(mat[u][i] == 1){
            if(color[i] == c){
                color[u] = -1;
                return false;
            }
        }
    }
    return true;
}

 

bool mColoring(vector<vector<int>> &mat, int u, vector<int>&color, int V, int m){
    if(u == V){
        return true;
    }
    for(int i=0; i<m; i++){
        if(isSafe(u, mat, i, V, m, color)){
            bool flag = mColoring(mat, u+1, color, V, m);
            if(flag){
                return true;
            }
        }
    }
    color[u] = -1;
    return false;
}

 

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int V = mat[0].size();
    vector<int> color(V, -1);
    for(int j=0; j<V; j++){
        if(color[j] == -1){
            if(!(mColoring(mat, j, color, V, m))){
                return "NO";
            }
        }
    }
    return "YES";
}