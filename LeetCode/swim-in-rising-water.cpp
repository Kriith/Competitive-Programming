class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
            int n = grid.size();
    
            auto bfs = [&](int t)->bool{
                if(grid[0][0] > t) return false;
                queue<pair<int, int>> q;
                q.push({0, 0});
                int df[] = {0, -1, 0, 1, 0};
                vector<vector<bool>> marked(n, vector<bool>(n, 0));
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second;
                    for(int i = 0; i < 4; i++){
                        int nx = x + df[i], ny = y + df[i+1];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n || marked[nx][ny]) continue;
                        if(grid[nx][ny] <= t){ 
                            q.push({nx, ny});
                            marked[nx][ny] = 1;
                        }
                    }
                    q.pop();
                }
                return marked[n-1][n-1];
            };
    
            int l = 0, r = n*n - 1, ans = n*n - 1;
            while(l <= r){
                int m = (r-l)/2 + l;
                if(bfs(m)) r = m - 1, ans = m;
                else l = m + 1;
            }
            return ans;
        }
    };