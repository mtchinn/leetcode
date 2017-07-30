//直接暴力sort, 好像居然比discuss里的递归二分快一丢丢？
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0; i<nums1.size(); ++i)
            v.push_back(nums1[i]);
        for(int i=0; i<nums2.size(); ++i)
            v.push_back(nums2[i]);
        sort(v.begin(), v.end());
        double ret = 0;
        if(v.size()%2)
            ret = (double)v[v.size()/2.0];
        else ret =(v[v.size()/2-1]+v[v.size()/2])/2.0;
        return ret;
    }
};