class Solution {
    public:
        int findMin(vector<int>& nums) {
            int l = 0, r = nums.size() - 1, ans = 5001;
            while(l <= r){
                int m = (r - l)/2 + l;
                if(nums[m] < nums[r]){
                    ans = min(ans, nums[m]);
                    r = m - 1;
                }
                else if(nums[m] > nums[r]){
                    ans = min(ans, nums[r]);
                    l = m + 1;
                }
                else{
                    ans = min(ans, nums[m]);
                    r--;
                }
            }
            return ans;
        }
    };