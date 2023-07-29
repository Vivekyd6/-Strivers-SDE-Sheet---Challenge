#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.

	if(n==1) return "1";
	string prev = writeAsYouSpeak(n-1);

	string res ;
	int cnt = 1;
	char digit = prev[0];

	for(int i=1;i<prev.length();i++){
		if(prev[i]==digit) cnt++;
		else {
			res+= to_string(cnt)+digit;
			cnt =1;
			digit = prev[i];
		}
	}	

	res+=to_string(cnt)+digit;
	return res;
}