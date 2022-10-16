class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         if(nums1.size()>nums2.size()) {
             vector<int>temp = nums1;
             nums1 = nums2;
             nums2 = temp;
         }
        int n = nums1.size();
        int m = nums2.size();
        int hi = n;
        int lo = 0;
        while(lo<=hi){
            int cut = (hi+lo)>>1;
            int cut1 = ((n+m+1)>>1) - cut;
            int l1 = cut== 0?INT_MIN: nums1[cut-1];
            int l2 = cut1==0? INT_MIN :nums2[cut1-1];
            int r1 = cut1==m?INT_MAX:nums2[cut1];
            int r2 = cut==n?INT_MAX:nums1[cut];
            if(l1<=r1&&l2<=r2) {
                if((n+m)&1) return max(l1,l2);
                return (double)(max(l1,l2) + min(r1,r2))/2.0;
            }
            if(l1>r1){hi = cut-1;}
            else lo = cut+1;
        }
        return 0.0;
        
        
        
    }
};