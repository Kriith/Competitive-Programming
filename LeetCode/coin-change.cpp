class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end(), greater<int>());
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i >= coins[j]) dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        if(dp[amount] <= amount) return dp[amount];
        else return -1;
    }
};