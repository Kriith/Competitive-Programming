class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++)
            if(grid[i][j] && (i == 0 || j == 0 || i == m-1 || j == n-1)) 
                dfs(i, j, grid);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++)
            if(grid[i][j]) ans++;
        return ans;
    }
    private:
    void dfs(int x, int y, vector<vector<int>>& grid){
        grid[x][y] = 0;
        int df[] = {0, -1, 0, 1, 0};
        for(int i = 0; i < 4; i++){
            int nx = x + df[i], ny = y + df[i+1];
            if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny]) dfs(nx, ny, grid);
        }
    }
};