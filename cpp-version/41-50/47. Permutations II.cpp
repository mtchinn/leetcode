class Solution {
public:
    vector<vector<int>>ret;
    void dfs(vector<int>& nums,vector<int>&per,vector<bool>&vis){
        if(per.size() == nums.size()){
            ret.push_back(per);
            return;
        }

        for(int i=0; i<nums.size(); ++i){
            if(!vis[i]){
                if(i>0 &&nums[i] == nums[i-1] && vis[i-1])
                    continue;
                vis[i] = true;
                per.push_back(nums[i]);
                dfs(nums,per,vis);
                per.pop_back();
                vis[i] = false;
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ret.clear();
        vector<bool>vis(nums.size(),false);
        vector<int>per;
        sort(nums.begin(),nums.end());
        dfs(nums,per,vis);
        return ret;
    }
};