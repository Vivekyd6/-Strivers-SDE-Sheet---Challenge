int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
// nlogn approach - 
    // sort(at,at+n);
    // sort(dt, dt+n);

    // int i=0,j = 0;
    // int p = 0;
    // int ans = 0;
    // while(i<n && j<n){
    //     if(at[i]<=dt[j]) i++, p++;
    //     else j++, p--;

    //     ans = max(ans , p);
    // }
    // return ans;

    // o(n) approach - 

    int platform[2361]={0};
    int ans =1;

    for(int i=0;i<n;i++){
        platform[at[i]]++;
        platform[dt[i]+1]--;
    }

    for(int i=1;i<2361;i++){
        platform[i]=platform[i]+platform[i-1];
        ans = max(ans , platform[i]);
    }

    return ans;
}