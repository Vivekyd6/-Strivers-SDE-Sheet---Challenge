#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int l, int m, int h) {
    vector<int> t;
    int left = l;
    int right = m + 1;

    while (left <= m && right <= h) {
        if (arr[left] <= arr[right])
            t.push_back(arr[left++]);
        else
            t.push_back(arr[right++]);
    }

    // adding remaining element on the left half
    while (left <= m)
        t.push_back(arr[left++]);
    while (right <= h)
        t.push_back(arr[right++]);

    for (int i = l; i <= h; i++)
        arr[i] = t[i - l];
}

int countPair(vector<int>& arr, int l, int m, int h) {
    int r = m + 1;
    int cnt = 0;

    for (int i = l; i <= m; i++) {
        while (r <= h && arr[i] > 2 * arr[r])
            r++;
        cnt += (r - (m + 1));
    }

    return cnt;
}

int mergeSort(vector<int>& arr, int l, int h) {
    int cnt = 0;
    if (l >= h)
        return cnt;

    int m = (l + h) / 2;
    cnt += mergeSort(arr, l, m);
    cnt += mergeSort(arr, m + 1, h);
    cnt += countPair(arr, l, m, h);
    merge(arr, l, m, h);

    return cnt;
}

int reversePairs(vector<int>& arr, int n) {
    return mergeSort(arr, 0, n - 1);
}


// int reversePairs(vector<int> &arr, int n){
// 	// Write your code here.	
// 	// bruteforce approach - 0(n*n) approach - 
// 	// int cnt = 0;

// 	// for(int i=0;i<n;i++){
// 	// 	for(int j=i+1;j<n;j++)
// 	// 	 if(arr[i]>2*arr[j]) cnt++;
// 	// }
// 	// return cnt;
   

//    // 2nd approach - we can use the merge sort algorithms to found out theres;
//     return mergeSort(arr , 0 , n-1);
   

// }