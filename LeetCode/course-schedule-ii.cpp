class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses, 0), ans;
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) if(!ind[i]) q.push(i);
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto i: adj[t]){
                ind[i]--;
                if(!ind[i]) q.push(i);
            }
        }
        if(ans.size() != numCourses) ans.clear();
        return ans;
    }
};