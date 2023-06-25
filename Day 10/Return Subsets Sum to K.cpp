
void solve(int idx , int k , int n ,vector<int>&arr ,  vector<int>&ds ,  vector<vector<int>>&ans, int sum){
    if(idx>=n) {
        if(k==0) ans.push_back(ds);
        return ;
    }

    sum+= arr[idx];
    ds.push_back(arr[idx]);

    solve(idx+1 , k-arr[idx], n ,arr,  ds , ans , sum);

    // pop_back 

    sum-=arr[idx];
    ds.pop_back();
    solve(idx+1 , k , n , arr , ds , ans , sum);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
     if(n==0) return {};

     vector<vector<int>>ans;
     vector<int>ds;
     solve(0 , k , n , arr , ds , ans , 0);
     return ans;

}