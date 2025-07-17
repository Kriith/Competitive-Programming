class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if(l == r) return l;
        while(l <= r){
            int m = (r-l)/2 + l;
            if(m == 0){
                if(nums[m] > nums[m+1]) return m;
                l = m + 1;
            }
            else if(m == nums.size() - 1){
                if(nums[m] > nums[m-1]) return m;
                r = m - 1;
            }
            else if(nums[m] > nums[m-1] && nums[m] > nums[m+1]) return m;
            else if(nums[m] > nums[m-1]) l = m + 1;
            else r = m - 1;
        }
        return 0;
    }
};