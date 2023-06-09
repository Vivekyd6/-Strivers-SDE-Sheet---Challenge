#include <bits/stdc++.h> 


long long merge(long long *arr, long long *tmp, int s, int m, int e) {
    long long cnt = 0;
    int i, j, k;
    i = s, j = m + 1, k = s;
    while (i <= m && j <= e) {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else {
            tmp[k++] = arr[j++];
            cnt = cnt + (m - i + 1);
        }
    }
    while (i <= m) tmp[k++] = arr[i++];
    while (j <= e) tmp[k++] = arr[j++];

    for (int i = s; i <= e; i++) arr[i] = tmp[i];
    return cnt;
}


long long mergesort(long long *arr ,long long* tmp,  int l , int h){
    long long cnt = 0;
    if(l<h){
        int mid = (l+h)/2;
        cnt+= mergesort(arr ,tmp,  l ,mid);
        cnt+= mergesort(arr ,tmp ,  mid+1 , h);
        cnt+= merge(arr ,tmp, l , mid , h);
    }
    return cnt;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    // bruteforce approach - 0(n*n)

    // long long cnt = 0;
    // for(int i=0;i<n;i++){
    //   for (int j = 1; j < n; j++) {
    //     if (arr[i] > arr[j] && i < j)
    //       cnt++;
    //   }
    // }
    // return cnt;


    // optimised approach - using merge sort (nlogn)
    long long *tmp ;
    tmp = new long long[n];
    return mergesort(arr ,tmp ,0 , n-1);
}