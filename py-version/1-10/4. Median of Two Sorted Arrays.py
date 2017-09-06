class Solution(object):
    def findKth(self,longarr,shortarr,k):
        m = len(longarr)
        n = len(shortarr)
        if m<n:
            return self.findKth(shortarr,longarr,k)
        if n==0:
            return longarr[k-1]
        if k==1:
            return min(longarr[0],shortarr[0])
        b1 = min(m,k//2)
        b2 = min(n,k//2)
        if(longarr[b1-1] < shortarr[b2-1]):
            arr = longarr[b1:]
            return self.findKth(arr,shortarr,k-b1);
        else:
            arr = shortarr[b2:]
            return self.findKth(longarr,arr,k-b2);

    def findMedianSortedArrays(self, nums1, nums2):
        left = (len(nums1)+len(nums2) + 1)//2;
        right =(len(nums1)+len(nums2) + 2)//2;
        return (self.findKth(nums1,nums2,left)+self.findKth(nums1,nums2,right))/2.0


        