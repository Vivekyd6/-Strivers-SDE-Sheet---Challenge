bool searchMatrix(vector<vector<int>>& mat, int target) {
        // approach 1 - bruteforce

        // we will be traversing in the whole list and find the target 
        // time complexity - 0(n*m);

        // approach 2 - use merge and sort , then apply two pointer approach 
        // time complexity - 0(n+m log(n+m)), space - 0(n+m);

        // approach 3 - binary search - as each row element are in sorted order 

        // approach 4 - two pointer approach ; - 
        // steps -  start with top-right diagonal or bottom left so that we have to move to only one side according to target element .
  
        int n = mat.size();
        int m = mat[0].size();
        
        // start with top -right corner
        int i = n-1, j = 0;
        while(i>=0 && j<m){
            if(mat[i][j]==target) return true;
            else if(mat[i][j]<target)j++;
            else i--;
        }

        return false;
}