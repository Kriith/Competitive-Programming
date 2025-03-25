class Solution {
    public:
        bool bfs(queue<pair<int, int>>& q, vector<vector<int>>& dist, bool flg, int t, vector<vector<int>>& grid){
            int n = grid.size(), m = grid[0].size(), d = 0;
            int df[] = {0, -1, 0, 1, 0};
            vector<vector<bool>> marked(n, vector<bool>(m, 0));
            while(!q.empty()){
                d++;
                int sz = q.size();
                while(sz--){
                    for(int i = 0; i < 4; i++){
                        int x = q.front().first + df[i], y = q.front().second + df[i+1];
                        if(x < 0 || x >= n || y < 0 || y >= m || marked[x][y] || grid[x][y] > 0) continue;
                        marked[x][y] = 1;
                        if(flg){
                            // cout<<x<<' '<<y<<' '<<d<<' '<<t<<' '<<dist[x][y]<<endl;
                            if(x == n-1 && y == m-1 && d+t <= dist[x][y]) return 1;
                            else if(d + t < dist[x][y]){
                                q.push({x, y});
                            }
                        }
                        else{ 
                            dist[x][y] = d;
                            q.push({x, y});
                        }
                    }
                    q.pop();
                }
            }
            return 0;
        }

        int maximumMinutes(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            queue<pair<int, int>> q;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        dist[i][j] = 0;
                    }
                }
            }
            bfs(q, dist, 0, 0, grid);
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < m; j++)
            //         cout<<dist[i][j]<<' ';
            //     cout<<endl;
            // }
            while(!q.empty()) q.pop();
            q.push({0, 0});
            int l = 0, r = 1e9, ans = -1;
            while(l <= r){
                int mid = (r-l)/2 + l;
                // cout<<l<<' '<<r<<' '<<mid<<' ';
                while(!q.empty()) q.pop();
                q.push({0, 0});
                bool b = bfs(q, dist, 1, mid, grid);
                // cout<<b<<endl;
                if(b) ans = mid, l = mid + 1; 
                else r = mid - 1;
            }
            return ans;
        }
    };