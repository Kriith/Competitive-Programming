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
                p[y] = x;
            }
        };
    
        int mst(int n, vector<vector<int>>& edges, int b, int p){
            int ans = 0;
            dsu ds(n);
            if(p >= 0){
                ans = edges[p][2];
                ds.merge(edges[p][0], edges[p][1]);
            }
            int nn = edges.size();
            for(int i = 0; i < nn; i++){
                if(i == b) continue;
                int x = ds.find(edges[i][0]), y = ds.find(edges[i][1]);
                if(x != y){
                    ds.merge(x, y);
                    ans += edges[i][2];
                }
            }
            int p0 = ds.find(0);
            for(int i = 1; i < n; i++){
                if(ds.find(i) != p0) return INT_MAX;
            }
            return ans;
        }
    
        struct cmp{
            bool operator()(vector<int>& v1, vector<int>& v2){
                return v1[2] < v2[2];
            }
        };
    
        vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
            int nn = edges.size();
            vector<int> crit, pscrit;
            for(int i = 0; i < nn; i++){
                edges[i].push_back(i);
            }
            sort(edges.begin(), edges.end(), cmp());
            int weight = mst(n, edges, -1, -1);
            for(int i = 0; i < nn; i++){
                int w1 = mst(n, edges, i, -1);
                if(w1 > weight){
                    crit.push_back(edges[i][3]);
                    continue;
                }
                int w2 = mst(n, edges, -1, i);
                if(w2 == weight) pscrit.push_back(edges[i][3]);
            }
            return {crit, pscrit};
        }
    };