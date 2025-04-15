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
    
            void merge(int a, int b){
                int x = find(a), y = find(b);
                if(x == y) return;
                p[y] = x;
            }
        };
    
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            int n = accounts.size();
            dsu ds(n);
            map<string, int> mp;
            for(int i = 0; i < n; i++){
                int m = accounts[i].size();
                for(int j = 1; j < m; j++){
                    if(mp.contains(accounts[i][j]))
                        ds.merge(mp[accounts[i][j]], i);
                    else mp[accounts[i][j]] = i;
                }
            }
    
            vector<vector<string>> temp(n);
            for(auto i : mp){
                int p = ds.find(i.second);
                temp[p].push_back(i.first);
            }
    
            vector<vector<string>> ans;
            for(int i = 0; i < n; i++){
                if(temp[i].size() == 0) continue;
                sort(temp[i].begin(), temp[i].end());
                temp[i].insert(temp[i].begin(), accounts[i][0]);
                ans.push_back(temp[i]);
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    };