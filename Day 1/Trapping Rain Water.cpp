#include <bits/stdc++.h> 
long getTrappedWater(long *h, int n){
    // Write your code here.

    // two pointer approach (Optimised solution)

         long l=0,r=n-1,res=0, leftmax=0,rightmax=0;
         while(l<=r){
             if(h[l]<=h[r]){
                 if(h[l]>=leftmax) leftmax=h[l];
                 else res+=leftmax-h[l];
                l++;
             }
             else {
                 if(h[r]>=rightmax) 
                     rightmax=h[r];
                 else 
                     res+=rightmax-h[r];
                r--;
             }
         }
         return res;
}
