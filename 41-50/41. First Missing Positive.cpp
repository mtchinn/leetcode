class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,bool>mymap;
        int maxSize = 0;
        for(int i=0;i<nums.size(); ++i){
            if(nums[i]>0){
                mymap.insert(pair<int,bool>(nums[i],true));
                maxSize = max(maxSize,nums[i]);
            }
        }
        for(int i=1; i<=maxSize; ++i){
            if(mymap.find(i) == mymap.end())
                return i;
        }
        return maxSize + 1;
    }
};