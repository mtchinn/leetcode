class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates,vector<int>&sl,int pos, int sum,int target){
        if(sum > target)
            return ;
        if(sum == target){
            res.push_back(sl);
            return;
        }
        for(int i=pos; i<candidates.size(); ++i){
            sl.push_back(candidates[i]);
            dfs(candidates,sl,i,sum + candidates[i],target);
            sl.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        vector<int>sl;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,sl,0,0,target);
        return res;
    }
};