class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right =height.size()-1;
        int res = 0;
        int maxLen = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>maxLen)
                    maxLen = height[left];
                else{
                    res += maxLen - height[left];
                    ++left;
                }
            }else{
                if(height[right]>maxLen)
                    maxLen = height[right];
                else{
                    res += maxLen - height[right];
                    --right;
                }
            }            
        }
        return res;
    }
};