class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++){
            if(mat[i][j]) mat[i][j] = -1;
            else q.push({0, i, j});
        }
        int df[] = {0, -1, 0, 1, 0};
        while(!q.empty()){
            vector<int> t = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = t[1] + df[i], y = t[2] + df[i+1];
                if(x >= 0 && y >= 0 && x < m && y < n && mat[x][y] < 0){
                    mat[x][y] = 1 + t[0];
                    q.push({mat[x][y], x, y});
                }
            }
        }
        return mat;
    }
};