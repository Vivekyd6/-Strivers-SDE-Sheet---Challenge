int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i=0, j=0;
    int zcnt =0;
    int ans = -1e5;
    for(;i<n;i++){
        if(arr[i]==0) zcnt++;
        while(zcnt>k){
            if(arr[j]==0)zcnt--;
            j++;
        }
       ans = max(ans , i-j+1);
    }

    return ans;
}
