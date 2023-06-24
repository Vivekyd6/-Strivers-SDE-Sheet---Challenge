#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{   
    int n = arr.size();
    unordered_map <int, int> mp;
    mp[0] = 1;
    int count = 0, curxor = 0;
    for (int i = 0; i < n; i++)
    {
        curxor ^= arr[i];
        if (mp[curxor ^ x] > 0)
            count += mp[curxor ^ x];
        mp[curxor]++;
    }
    return count;
}