class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int ret = 0;

        while(start<end){
            int h = min(height[start],height[end]);
            ret = max(ret,(end-start)*h);
            while(end>start && height[end]<=h) --end;
            while(end>start && height[start]<=h) ++start;
        }

        return ret;
    }
};