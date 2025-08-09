class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        int nx[] = {-1, 0, 1, -1, 1, -1, 0, 1}, ny[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        set<vector<int>> s;
        s.insert({1, 0, 0});
        while(!s.empty()){
            vector<int> t = (*s.begin());
            s.erase(s.begin());
            for(int i = 0; i < 8; i++){
                int x = t[1] + nx[i], y = t[2] + ny[i];
                if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y]) continue;
                if(dist[x][y] > t[0] + 1){
                    dist[x][y] = t[0] + 1;
                    s.insert({dist[x][y], x, y});
                }
            }
        }
        return ((dist[n-1][n-1] == INT_MAX)?-1:dist[n-1][n-1]);
    }
};