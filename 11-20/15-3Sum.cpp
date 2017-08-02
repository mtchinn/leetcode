class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ret;
        std::sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); ++i){
            int target = -nums[i];
            int low = i+1;
            int high =nums.size()-1;
            while(low<high){
                int sum = nums[low]+nums[high];
                if(sum < target)
                    ++low;
                else if(sum > target)
                    --high;
                else{
                    vector<int>t;
                    t.push_back(nums[i]);
                    t.push_back(nums[low]);
                    t.push_back(nums[high]);
                    ret.push_back(t);
                    int k = nums[low];
                    while(nums[low] == k) ++low;
                    k = nums[high];
                    while(nums[high] == k) --high;
                }
            }
            int k = nums[i];
            while(nums[i+1]==k) ++i;
        }
        return ret;
    }
};