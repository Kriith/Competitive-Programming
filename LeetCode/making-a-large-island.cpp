class Solution {
public:

struct dsu{
    vector<int> data;

    dsu(int n){
        data.assign(n, -1);
    }

    int find(int x){
        return data[x] < 0?x:data[x] = find(data[x]);
    }

    int getsz(int x){
        return -data[find(x)];
    }

    bool merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y], data[y] = x;
        return true;
    }
};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), df[] = {0, -1, 0, 1, 0}, ans = 0, n1 = 0, n0 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) n1++;
                else n0++;
            }
        }
        if(!n0) return n*n;
        if(!n1) return 1;
        dsu s(n*n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    int curr = n*i+j;
                    for(int k = 0; k < 2; k++){
                        int x = i + df[k], y = j + df[k+1];
                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y]){
                            s.merge(curr, x*n + y);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j]){
                    unordered_set<int> neigh;
                    for(int k = 0; k < 4; k++){
                        int x = i + df[k], y = j + df[k+1];
                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y])
                            neigh.insert(s.find(x*n+y));
                    }
                    int curr = 0;
                    for(auto v: neigh)
                        curr += s.getsz(v);
                    ans = max(ans, curr+1);
                }
            }
        }
        return ans;
    }
};