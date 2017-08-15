class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        vector<int>ret;
        int mid;
        while(low<=high){
            mid = (low + high) / 2;
            if(nums[mid]<target)
                low = mid+1;
            else if(nums[mid]>target)
                high = mid-1;
            else {
                int k=mid;
                while(k>=1 && nums[k-1] == target)
                    --k;
                ret.push_back(k);
                k = mid;
                while(k<nums.size()-1 && nums[k+1] == target)
                    ++k;
                ret.push_back(k);
                break;
            }
        }
        if(ret.size()==0){
            ret.push_back(-1);
            ret.push_back(-1);
        }
        return ret;
    }
};