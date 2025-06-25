class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            // vector<int> t(amount+1, 0);
            for(int j = coins[i]; j <= amount; j++){
                // t[j] = dp[j];
                // if(j >= coins[i]) t[j] += (long long)t[j - coins[i]];
                dp[j] += dp[j - coins[i]];
            }
            // dp = t;
        }
        return dp[amount];
    }
};