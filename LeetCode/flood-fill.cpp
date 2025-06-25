class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size(), clr = image[sr][sc];
        if(clr == color) return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int df[] = {0, 1, 0, -1, 0};
        while(!q.empty()){
            pair<int, int> t = q.front();
            q.pop();
            image[t.first][t.second] = color;
            for(int i = 0; i < 4; i++){
                int x = t.first + df[i], y = t.second + df[i+1];
                if(x < n && x >= 0 &&  y < m && y >= 0 && image[x][y] == clr)
                    q.push({x, y});
            }
        }
        return image;
    }
};