class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0; 
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j]) dp[i][j] = -1;
                else dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 1; i < m; i++)
            if(dp[i-1][0] > 0 && dp[i][0] >= 0) dp[i][0] = 1;
        for(int i = 1; i < n; i++)
            if(dp[0][i-1] > 0 && dp[0][i] >= 0) dp[0][i] = 1;
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(dp[i][j] < 0) continue;
                dp[i][j] = max(dp[i-1][j], 0) + max(0, dp[i][j-1]);
            }
        }
        return max(0, dp[m-1][n-1]);
    }
};