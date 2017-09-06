class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1 ; i<nums.size(); ++i){
            if(nums[i] == v[v.size()-1]) {
                continue;
            }
            else{
               v.push_back(nums[i]);
            }
        }
        nums = v;
        return nums.size();
    }
};