#include<bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    int l = 1, h = 1e5;
    while (l < h) {
        int mid = l + (h - l) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (cnt > (n * m) / 2) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}
