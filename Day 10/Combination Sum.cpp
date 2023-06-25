class Solution {
public:
    void solve(int idx , vector<int>&ds , vector<vector<int>>& res , vector<int>& candidates , int target){
         if(target==0){
                res.push_back(ds);
                return;
            }
        
        if(target<0 ||  idx>=candidates.size()) return;
        // pick the current element 
        ds.push_back(candidates[idx]);
        solve(idx , ds , res , candidates , target-candidates[idx]);
        ds.pop_back();
        solve(idx+1 , ds , res , candidates , target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ds;
        solve(0 , ds , res , candidates , target);
        return res;
    }
};