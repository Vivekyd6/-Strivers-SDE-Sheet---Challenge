#include <bits/stdc++.h> 
int chessTournament(vector<int> positions , int n ,  int c)
{
	sort(positions.begin(),positions.end());
	long long i=1;
	long long j=positions[n-1];
	long long ans=0;
	while(i<=j)
	{
		long long m=i+(j-i)/2;
		int cnt = 1;
		int  prev = positions[0];
		for(int i=1;i<n;i++){
			if(positions[i]-prev>=m){
				cnt++;
				prev = positions[i];
			}
		}
	    if(cnt>=c)
		{
			i=m+1;
			ans=m;
		}
		else j=m-1;
	}
	return ans;
}