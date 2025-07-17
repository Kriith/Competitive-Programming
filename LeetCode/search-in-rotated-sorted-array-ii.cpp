class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = (r-l)/2 + l;
            if(nums[m] == target) return 1;
            if(nums[m] == nums[l] && nums[m] == nums[r]) l++, r--;
            else if(nums[l] <= nums[m]){
                if(target <= nums[m] && target >= nums[l]) r = m - 1;
                else l = m + 1;
            }
            else{
                if(target <= nums[r] && target >= nums[m]) l = m + 1;
                else r = m - 1;
            }
        }
        return 0;
    }
};