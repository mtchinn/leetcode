class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid = -1;
        while(low<=high){
            mid = (low + high) / 2;
            if(nums[mid] <target)
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
            else break;
        }
        if(nums[mid]>=target) return mid;
        return mid+1;
    }
};