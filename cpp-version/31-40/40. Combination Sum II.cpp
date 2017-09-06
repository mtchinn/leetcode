class Solution {
public:
    vector<vector<int>> res;
    map<string,bool>myhash;
    void dfs(vector<int>& candidates,vector<int>&sl,int pos, int sum,int target,string hashcode){
        if(sum == target){
            if(myhash.find(hashcode) == myhash.end()) {
                res.push_back(sl);
                myhash[hashcode] = true;
            }
            return;
        }
        for(int i=pos+1; i<candidates.size(); ++i){
            if(sum+candidates[i] <= target) {
                sl.push_back(candidates[i]);
                hashcode.push_back(candidates[i] + '0');
                dfs(candidates, sl, i, sum + candidates[i], target, hashcode);
                sl.pop_back();
                hashcode.pop_back();
            }else return;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        myhash.clear();
        vector<int>sl;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,sl,-1,0,target,"");
        return res;
    }
};