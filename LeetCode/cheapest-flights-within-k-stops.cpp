class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto i: flights){
            adj[i[0]].push_back({i[1], i[2]});
            // adj[i[1]].push_back({i[0], i[2]});
        }
        set<vector<int>> s;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        s.insert({0, dist[src], src});
        while(!s.empty()){
            vector<int> t = *s.begin();
            s.erase(s.begin());
            if(t[0] > k) continue;
            for(auto it: adj[t[2]]){
                int ad = it.first, cost = it.second;
                if(dist[ad] > t[1] + cost && t[0] <= k){
                    dist[ad] = t[1] + cost;
                    s.insert({t[0] + 1, dist[ad], ad});
                }
            }
        }
        return (dist[dst] == INT_MAX)?-1:dist[dst];
        //bellman ford implementation
        /*
        vector<int> currdist(n, INT_MAX), prevdist(n, INT_MAX);
        currdist[src] = 0;
        for(int i = 0; i <= k; i++){
            prevdist = currdist;
            for(auto it: flights)
                if(prevdist[it[0]] < INT_MAX)
                    currdist[it[1]] = min(currdist[it[1]], prevdist[it[0]] + it[2]);
        }
        return (currdist[dst] == INT_MAX)?-1:currdist[dst];
        */
    }
};