class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> vis(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(isConnected[i][j]) adj[i].push_back(j);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans;
    }

private:
    void dfs(int i, vector<vector<int>> &adj, vector<bool>& vis){
        if(vis[i]) return;
        vis[i] = 1;
        for(auto it: adj[i]){
            if(!vis[it]) dfs(it, adj, vis);
        }
        return;
    }
};