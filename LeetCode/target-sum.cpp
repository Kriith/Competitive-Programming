class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), tot = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > tot) return 0;
        vector<int> dp(2*tot + 1, 0);
        dp[tot + nums[0]] += 1;
        dp[tot - nums[0]] += 1;
        for(int i = 1; i < n; i++){
            vector<int> t(2*tot + 1, 0);
            for(int j = -tot; j <= tot; j++){
                if(j + nums[i] <= tot) t[j + nums[i] + tot] += dp[j + tot];
                if(j - nums[i] >= -tot) t[j - nums[i] + tot] += dp[j + tot];
            }
            dp = t;
        }
        return dp[target + tot];
    }
};