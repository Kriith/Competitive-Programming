class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> a, b;
        if(m > n) a = nums2, b = nums1;
        else a = nums1, b = nums2;
        m = a.size(), n = b.size();
        int l = 0, r = m;
        while(l <= r){
            int m1 = (r - l)/2 + l, m2 = (n+m+1)/2 - m1;
            int l1 = (m1 == 0)?INT_MIN:a[m1 - 1], r1 = (m1 == m)?INT_MAX:a[m1];
            int l2 = (m2 == 0)?INT_MIN:b[m2 - 1], r2 = (m2 == n)?INT_MAX:b[m2];
            if(l1 <= r2 && l2 <= r1){
                if((n+m)&1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2))/2.0;
            }
            if(l1 > r2) r = m1 - 1;
            else l = m1 + 1;
        }
        return 0;
    }
};
/*
i dont understand ts :(
*/