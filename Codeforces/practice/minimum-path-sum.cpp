class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = grid[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > 0) cost[i][j] = min(cost[i][j], cost[i-1][j] + grid[i][j]);
                if(j > 0) cost[i][j] = min(cost[i][j], cost[i][j-1] + grid[i][j]);
            }
        }
        return cost[m-1][n-1];
    }
};