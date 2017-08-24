class Solution {
public:
	//仍然参考后面的discuss啊啊啊
	//大佬好厉害啊啊啊qwq
	int jump(vector<int>& nums){
        int jumps = 0;
        int reachTheFarest = 0;
        int edge = 0;
        for(int i=0;i<nums.size()-1; ++i){
            reachTheFarest = max(reachTheFarest,i+nums[i]);

            //到达了最大能到的点，jumps+1
            if(i == edge){
                ++jumps;
                edge = reachTheFarest;
            }

        }
        return jumps;
    }
};