#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &A, int n)
{
	// Write your code here
	// approach 1 - use simple traversal and made a count variable to count , so if count = 2 , repeating else cnt = 0 , missing .
	// approach 2 - use of map to store their frequency 

	// optimised approach - use of sum and square sum to calculate it 

	long long int len = A.size();
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       Sum_N -= (long long int)A[i];
       Sum_NSq -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;    
	return {(int) missingNumber , (int) repeating}; 
	
}
