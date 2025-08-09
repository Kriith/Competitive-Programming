class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<vector<int>>> adj(n);
        for(auto i: edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        auto djikstra = [&](int u)->int{
            vector<int> dist(n, INT_MAX);
            set<vector<int>> s;
            dist[u] = 0;
            s.insert({0, u});
            while(!s.empty()){
                vector<int> t = *s.begin();
                s.erase(s.begin());
                for(auto i: adj[t[1]]){
                    if(dist[i[0]] > i[1] + t[0]){
                        dist[i[0]] = i[1] + t[0];
                        s.insert({dist[i[0]], i[0]});
                    }
                }
            }
            int cnt = 0;
            dist[u] = INT_MAX;
            for(int i = 0; i < n; i++)
                if(dist[i] <= distanceThreshold) cnt++;
            return cnt;
        };
        int min = INT_MAX, ans = 0;
        for(int i = 0; i < n; i++){
            int t = djikstra(i);
            // cout<<t<<' '<<i<<endl;
            if(t <= min){
                ans = i;
                min = t;
            }
        }
        return ans;
    }
};