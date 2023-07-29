#include <bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int, int>> q;
    int cnt = 0;
    int days = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) total++;
            if (grid[i][j] == 2) q.push({i, j});
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        int size = q.size();
        cnt += size;
        while (size--) {
            auto tmp = q.front();
            int x = tmp.first;
            int y = tmp.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i]; 
                // Fix the error here (used y instead of x)

                // valid
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if (!q.empty()) days++;
    }

    if (total != cnt) return -1;
    return days;
}
