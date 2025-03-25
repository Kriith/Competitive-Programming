class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n, 0);
            for(int i = 0; i < n; i++){
                if(color[i] == 0 && !dfs(i, color, 1, graph)) return false;
            }
            return true;
        }
    
        bool dfs(int ind, vector<int>& color, int col, vector<vector<int>>& graph){
            color[ind] = col;
            int n = graph[ind].size();
            for(int i = 0; i < n; i++)
                if((color[graph[ind][i]] == 0 && !dfs(graph[ind][i], color, 3 - col, graph)) || color[graph[ind][i]] == col) return false;
            return true;
        }   
    };