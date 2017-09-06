class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = INT_MAX;
        int sum = 0;
        for(int i=0; i<nums.size(); ++i){
            int tar = target - nums[i];
            int low = i+1;
            int high = nums.size()-1;
            while(low<high){
                int bias = tar - nums[low] - nums[high];
                if(abs(bias)<closest){
                    closest = abs(bias);
                    sum = nums[i] + nums[low] + nums[high];
                }
                if(bias<0) --high;
                else if(bias>0) ++low;
                else ++low,--high;
            }
        }
        return sum;
    }
};