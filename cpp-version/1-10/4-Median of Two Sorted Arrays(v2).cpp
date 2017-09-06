//俩个数组递归二分
	class Solution {
	public:
	    int getKth(vector<int<& lo, vector<int<& sml ,int k){
	        int m = lo.size();
	        int n = sml.size();
	        if(m < n)
	            return getKth(sml,lo,k);
	        if(n == 0) return lo[k-1];
	        if(k == 1) return min(lo[0],sml[0]);

	        int bias1 = min(m, k>>1);
	        int bias2 = min(n, k>>1);

	        if(lo[bias1-1] < sml[bias2-1]){
	            std::vector<int>sub(lo.begin()+bias1,lo.end());
	            return getKth(sub,sml,k-bias1);
	        }else{
	            std::vector<int>sub(sml.begin()+bias2,sml.end());
	            return getKth(lo,sub,k-bias2);
	        }
	    }
	    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	        int left = (nums1.size() + nums2.size() +1)>>1;
	        int right = (nums1.size() + nums2.size() +2)>>1;
	        return (getKth(nums1,nums2,left) + getKth(nums1,nums2,right))/2.0;
	    }
	};