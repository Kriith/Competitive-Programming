class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>> ans;
        vector<bool> vis(n, 0);
        vector<int> tin(n, 0), low(n, INT_MAX);
        dfs(0, -1, adj, ans, vis, tin, low, 0);
        return ans;
    }

private:
    void dfs(int u, int p, vector<vector<int>>& adj, vector<vector<int>>& ans, vector<bool>& vis, vector<int>& tin, vector<int>& low, int time){
        vis[u] = 1;
        tin[u] = low[u] = ++time;
        for(auto i: adj[u]){
            if(i == p) continue;
            if(vis[i]) low[u] = min(low[u], low[i]);
            else{
                dfs(i, u, adj, ans, vis, tin, low, time);
                low[u] = min(low[u], low[i]);
                if(low[i] > tin[u]) ans.push_back({u, i});
            }
        }
    }
};