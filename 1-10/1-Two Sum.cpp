class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>mmp;
        for(int i=0; i<nums.size(); ++i) {
                mmp[nums[i]].push_back(i);
        }
        vector<int>ret;
        for(int i=0; i<nums.size(); ++i){
            int delta = target - nums[i];
            if(nums[i] == delta){
                if(mmp[nums[i]].size()>1){
                    ret.push_back(i);
                    ret.push_back(mmp[nums[i]][1]);
                    break;
                }
            }else if(mmp.find(delta)!=mmp.end()){
                ret.push_back(i);
                ret.push_back(mmp[delta][0]);
                break;
            }
        }
        return ret;
    }
};