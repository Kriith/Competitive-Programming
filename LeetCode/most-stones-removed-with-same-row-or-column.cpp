class Solution {
    public:
        struct dsu{
            int n;
            vector<int> p;
    
            dsu(int n){
                this->n = n;
                p.resize(n+1, 0);
                for(int i = 1; i <= n; i++) p[i] = i;
            }
    
            int find(int x){
                if(p[x] != x) p[x] = find(p[x]);
                return p[x];
            }
    
            void merge(int x, int y){
                if(x == y) return;
                p[y] = x;
            }
        };
    
        int removeStones(vector<vector<int>>& stones) {
            int n = stones.size(), mxr = 0, mxc = 0;
            for(int i = 0; i < n; i++) 
                mxr = max(mxr, stones[i][0]), mxc = max(mxc, stones[i][1]);
            dsu ds(mxr + mxc + 1);
            map<int, bool> mp;
            for(int i = 0; i < n; i++){
                int x = ds.find(stones[i][0]);
                int y = ds.find(stones[i][1] + mxr + 1);
                ds.merge(x, y);
                mp[x] = mp[y] = 1;
            }
            int cnt = 0;
            for(auto i : mp){
                if(i.first == ds.find(i.first)) cnt++;
            }
            return (n - cnt);
        }
    };