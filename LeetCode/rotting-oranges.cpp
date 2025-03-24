class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int, int>> q;
            int m = grid.size(), n = grid[0].size();
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++)
                    if(grid[i][j] == 2) q.push({i, j});
            }
            int cursz = q.size(), nxsz = 0, t = -1;
            while(cursz > 0 && !q.empty()){
                int x = q.front().first, y = q.front().second;
                cout<<x<<' '<<y<<' '<<cursz<<' '<<grid[x][y]<<' '<<t<<endl;
                if(x > 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                    nxsz++;
                } 
                if(x > 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1, y});
                    nxsz++;
                } 
                if(y > 0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x, y-1});
                    nxsz++;
                } 
                if(x < m-1 && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1, y});
                    nxsz++;
                } 
                if(y < n-1 && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                    nxsz++;
                } 
                q.pop();
                cursz--;
                if(cursz == 0){
                    cursz = nxsz;
                    t++;
                    nxsz = 0;
                }
            }
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++)
                    if(grid[i][j] == 1) return -1;
            }
            return max(0, t);
        }
    };