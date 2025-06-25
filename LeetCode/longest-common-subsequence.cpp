class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                int s = 0, t = 0;
                if(text1[i] == text2[j]) t++;
                if(i > 0) s = max(s, dp[i-1][j]);
                if(j > 0) s = max(s, dp[i][j-1]);
                if(i > 0 && j > 0) t += dp[i-1][j-1];
                dp[i][j] = max(s, t);
            }
        }
        return dp[n1-1][n2-1];
    }
};