#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   // approach using dutch national flag algorithm.
   int low = 0;
   int mid = 0;
   int high = n-1;


   while(mid<=high){
       if(arr[mid]==0){
          swap(arr[low++], arr[mid++]);
       }
       else if(arr[mid]==1) mid++;
       else swap(arr[mid],arr[high--]);
   }
}