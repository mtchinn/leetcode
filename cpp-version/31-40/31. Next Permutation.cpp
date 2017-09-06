class Solution {
public:
    void swap(vector<int>& nums, int x, int y){
        nums[x] = nums[x] + nums[y];
        nums[y] = nums[x] - nums[y];
        nums[x] = nums[x] - nums[y];
    }
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-2;
        while(index>=0 && nums[index+1]<=nums[index])
            --index;
        if(index>=0) {
            int j = nums.size() - 1;
            while (j >index  && nums[j]<=nums[index]) {
                --j;
            }
            swap(nums,index,j);
            reverse(nums.begin()+index+1,nums.end());
        }else reverse(nums.begin(),nums.end());
    }
};