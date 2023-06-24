bool isSafe(vector<vector<int>>& board , int row , int col , int n){
    // checking same column
    for(int i=0;i<row;i++){
        if(board[i][col]==1) return false;
    }

    // checking same diagonal 
    for(int i=row , j = col;i>=0 && j>=0 ;i--,j--){
        if(board[i][j]==1) return false;
    }

    // reverse diagonal 

    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]==1) return false;
    }

    return true;
}
void solve(vector<vector<int>>& board , int row , int n , vector<vector<int>>&ans){
     if(row==board.size()) {
        vector<int>tmp;
        for(auto it:board) {
          for (auto d : it) {
            tmp.push_back(d);
          }
        }
        ans.push_back(tmp);
        return;
     }
    for(int col= 0;col<n;col++){
        if(isSafe(board , row , col , n)){
            board[row][col]=1;
            solve(board , row+1 , n , ans);
            board[row][col]=0;
        }
    }
}


vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    // we can solve it using backtracking - recursion
    vector<vector<int>>ans;
    if(n<=0) return {{}};
    vector<vector<int>>board(n , vector<int>(n,0));
    solve(board , 0 , n , ans);
    return ans;
}