class Solution {
public:
    const int MOD = 1e9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(7, vector<int>(16)));
        return rec(0, 0, 0, n, rollMax, dp);
    }

    int rec(int i, int j, int x, int n, vector<int>& rollMax, vector<vector<vector<int>>>& dp) {
        if(i == n)
            return 1;

        if(dp[i][j][x])
            return dp[i][j][x];

        int sum = 0;
        for(int k = 1; k <= 6; k++) {
            if(k != j)
                sum = (sum + rec(i + 1, k, 1, n, rollMax, dp))%MOD;
            else if(x < rollMax[j - 1])
                sum = (sum + rec(i + 1, k, x + 1, n, rollMax, dp))%MOD;
        }
        return dp[i][j][x] = sum;
    }
};