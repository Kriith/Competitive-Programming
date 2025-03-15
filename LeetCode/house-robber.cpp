class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            if(n == 2) return max(nums[1], nums[0]);
            int prev = 0, curr = 0;
            for(int i = 0; i < n; i++){
                int t = curr; 
                curr = max(prev + nums[i], curr);
                prev = t;
            } 
            return max(curr, prev);
        }
    };