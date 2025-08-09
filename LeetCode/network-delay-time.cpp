class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        for(auto i: times) adj[i[0]].push_back({i[1], i[2]});
        vector<int> dist(n+1, INT_MAX);
        dist[0] = dist[k] = 0;
        set<vector<int>> s;
        s.insert({0, k});
        while(!s.empty()){
            vector<int> t = *s.begin();
            s.erase(s.begin());
            for(auto i: adj[t[1]]){
                if(dist[i[0]] > t[0] + i[1]){
                    dist[i[0]] = t[0] + i[1];
                    s.insert({dist[i[0]], i[0]});
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return (ans == INT_MAX)?-1:ans;
    }
};