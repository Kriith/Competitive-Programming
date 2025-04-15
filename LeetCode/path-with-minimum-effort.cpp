class Solution {
    public:
        struct cmp{
            bool operator()(vector<int> v1, vector<int> v2){
                return v1[2] > v2[2];
            }
        };
    
        int minimumEffortPath(vector<vector<int>>& heights) {
            int n = heights.size(), m = heights[0].size(), df[] = {0, -1, 0, 1, 0};
            priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            dist[0][0] = 0;
            pq.push({0, 0, 0});
            while(!pq.empty()){
                vector<int> v = pq.top();
                for(int i = 0; i < 4; i++){
                    int nx =  v[0] + df[i], ny = v[1] + df[i + 1];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    int diff = max(v[2], abs(heights[v[0]][v[1]] - heights[nx][ny]));
                    if(dist[nx][ny] > diff){
                        dist[nx][ny] = diff;
                        pq.push({nx, ny, diff});
                    }
                }
                pq.pop();
            }
            return dist[n-1][m-1];
        }
    };