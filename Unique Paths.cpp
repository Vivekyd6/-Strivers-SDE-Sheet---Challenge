#include <bits/stdc++.h>


int solve(int r , int c , int m , int n,vector<vector<int>>&dp){
	// edge and base case ;
	if(r>=m || c>=n) return 0;
	if(r== m-1 && c == n-1) return 1;

	if(dp[r][c]!=-1) return dp[r][c];

	int right = solve(r , c+1 , m , n,dp);
	int down = solve(r+1 , c , m , n,dp);

	return dp[r][c] = right+ down;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return solve(0 , 0 , m , n,dp);
}