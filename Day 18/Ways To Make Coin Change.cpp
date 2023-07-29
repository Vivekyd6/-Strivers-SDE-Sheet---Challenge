#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long long >> dp(n, vector<long long >(value + 1, 0));
    for (int i = 0; i <= value; i++)
        dp[0][i] = value % denominations[0] == 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= value; j++) {
        long notTake = dp[i - 1][j];
        long take = 0;
        if (denominations[i] <= j)
            take = dp[i][j - denominations[i]];

        dp[i][j] = take + notTake;
        }
    }
   return dp[n - 1][value];
}