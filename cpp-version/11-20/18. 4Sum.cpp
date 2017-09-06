class Solution {
public:
    map<int,bool>myhash;
    void func(vector<int>& nums,int low1,int high1,int target,vector<vector<int>>&ret){
        int sum = nums[low1]+ nums[high1];
        int bias = target - sum;
        int low2 = low1 +1;
        int high2 = high1-1;
        bool flag2= false;
        while(low2<high2){
            int sum2 =nums[low2] + nums[high2];
            if(sum2 == bias){
                vector<int>t;
                t.push_back(nums[low1]);
                t.push_back(nums[low2]);
                t.push_back(nums[high2]);
                t.push_back(nums[high1]);
                int h = nums[low1]*1000+nums[low2]*100 + nums[high1]*10+nums[high2];
                if(myhash.find(h)==myhash.end()) {
                    ret.push_back(t);
                    myhash[h] = true;
                }
                int k = nums[low2];
                while(nums[low2] == k) ++low2;
            }
            if(sum2 < bias){
                int k = nums[low2];
                while(nums[low2] == k) ++low2;
            }
            if(sum2 > bias){
                int k = nums[high2];
                while(nums[high2] == k) --high2;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ret;
        sort(nums.begin(),nums.end());
        int low1 =0;
        int high1 = nums.size()-1;
        bool flag = false;
        for(int i=0; i<nums.size(); ++i){
            for(int j = i+3; j<nums.size(); ++j) {
                func(nums, i, j, target, ret);
            }
        }
        return ret;
    }
};