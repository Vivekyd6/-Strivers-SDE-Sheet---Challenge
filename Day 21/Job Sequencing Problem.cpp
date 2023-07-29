// Bruteforce - #include <vector>
#include <algorithm>

bool compare(vector<int>& a, vector<int>& b) {
    return a[2] > b[2]; // Sort jobs based on profit in descending order
}

vector<int> jobScheduling(vector<vector<int>>& jobs) {
    // Step 1: Sort the jobs based on their profits in descending order
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find the maximum deadline to create a time slot array
    int maxDeadline = 0;
    for (const vector<int>& job : jobs) {
        maxDeadline = max(maxDeadline, job[1]);
    }

    // Step 3: Create a time slot array to keep track of time slots
    vector<bool> timeSlots(maxDeadline + 1, false);
    int totalProfit = 0;
    int numJobsScheduled = 0;

    // Step 4: Assign jobs to time slots
    for (const vector<int>& job : jobs) {
        int deadline = job[1];
        // Find the latest possible time slot for the current job
        while (deadline > 0 && timeSlots[deadline]) {
            deadline--;
        }
        // If a time slot is available for the current job, assign it
        if (deadline > 0) {
            timeSlots[deadline] = true;
            totalProfit += job[2];
            numJobsScheduled++;
        }
    }

    // Step 5: Return the result as a vector [number of jobs, maximum profit]
    return {numJobsScheduled, totalProfit};
}


// optimised using union set 
#include <vector>
#include <algorithm>

class UnionFind {
    std::vector<int> parent;

public:
    UnionFind(int n) : parent(n + 1) {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

bool compare(vector<int>& a, vector<int>& b) {
    return a[2] > b[2]; // Sort jobs based on profit in descending order
}

vector<int> jobScheduling(vector<vector<int>>& jobs) {
    // Step 1: Sort the jobs based on their profits in descending order
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find the maximum deadline to create a time slot array
    int maxDeadline = 0;
    for (const vector<int>& job : jobs) {
        maxDeadline = max(maxDeadline, job[1]);
    }

    UnionFind uf(maxDeadline);

    int totalProfit = 0;
    int numJobsScheduled = 0;

    // Step 3: Assign jobs to time slots using Union-Find
    for (const vector<int>& job : jobs) {
        int deadline = job[1];
        int availableSlot = uf.find(deadline);
        if (availableSlot > 0) {
            uf.unite(availableSlot, availableSlot - 1);
            totalProfit += job[2];
            numJobsScheduled++;
        }
    }

    // Step 4: Return the result as a vector [number of jobs, maximum profit]
    return {numJobsScheduled, totalProfit};
}
