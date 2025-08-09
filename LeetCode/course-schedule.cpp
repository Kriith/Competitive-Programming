class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites) adj[i[1]].push_back(i[0]);
        vector<short> colour(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(colour[i] == 0 && !dfs(i, adj, colour)) return 0;
        }
        return 1;
    }
private: 
    bool dfs(int t, vector<vector<int>>& adj, vector<short>& colour){
        if(colour[t] == 1) return false;
        if(colour[t] == 2) return true;
        colour[t]++;
        for(auto i: adj[t]) if(!dfs(i, adj, colour)) return false;
        colour[t]++;
        return true;
    }
};