using ll = long long;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n);
        for(auto i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        set<vector<ll>> s;
        vector<ll> dist(n, LONG_LONG_MAX), ways(n, 0);
        dist[0] = 0, ways[0] = 1;
        s.insert({0, 0});
        const int mod = 1e9+7;
        while(!s.empty()){
            vector<ll> t = *s.begin();
            s.erase(s.begin());
            for(auto i: adj[t[1]]){
                if(dist[i[0]] == t[0] + i[1]) 
                    ways[i[0]] = (ways[i[0]] + ways[t[1]])%mod;
                else if(dist[i[0]] > t[0] + i[1]){
                    dist[i[0]] = t[0] + i[1];
                    s.insert({dist[i[0]], i[0]});
                    ways[i[0]] = ways[t[1]];
                }
            }
        }
        return ways[n-1];
    }
};