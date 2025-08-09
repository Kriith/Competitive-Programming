class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<short> col(n, 0);
        set<int> s;
        for(int i = 0; i < n; i++) s.insert(i);
        for(int i = 0; i < n; i++){
            if(!col[i]) dfs(i, graph, col, s);
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }

private:
    bool dfs(int t, vector<vector<int>>& adj, vector<short>& col, set<int>& s){
        if(col[t] == 1){
            s.erase(t);
            return true;
        }
        if(col[t] == 2){
            if(s.find(t) == s.end()){
                s.erase(t);
                return true;
            }
            return false;
        }
        col[t]++;
        for(auto i: adj[t]){
            if(dfs(i, adj, col, s)){
                if(s.find(t) != s.end())
                    s.erase(t);
            }
        }
        col[t]++;
        return (s.find(t) == s.end());
    }
};