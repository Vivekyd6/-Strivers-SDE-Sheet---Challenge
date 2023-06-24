#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.

	   // approach 1 - use sorting 
	   // approach 2 - use of hash map 

	   // approach 3 - use of 0(n) solution , 0(1) space solutiion 
       
      int cnt = 0;
	  int res = -1;

	  for(int i=0;i<n;i++){
		  if(cnt==0) res = arr[i], cnt++;
		  else if(res!=arr[i]) cnt--;
		  else if(res == arr[i]) cnt++;
	  }



	  cnt = 0;

          for (int i = 0; i < n; i++) {
            if (arr[i] == res)
              cnt++;
            if (cnt > n / 2)
              return res;
          }
          return -1;
}
