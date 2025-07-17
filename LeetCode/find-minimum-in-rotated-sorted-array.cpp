class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX, l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = (r-l)/2 + l;
            if(nums[r] <= nums[m]) l = m + 1;
            else r = m - 1;
            ans = min(nums[m], ans);
        }
        return ans;
    }
};