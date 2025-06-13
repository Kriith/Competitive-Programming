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

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0, dp[0][1] = nums[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};