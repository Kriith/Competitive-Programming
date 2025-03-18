class Solution {
    public:
    
        struct cmp{
            bool operator()(pair<int, char> p1, pair<int, char> p2){
                return p1.first < p2.first;
            }
        };
    
        string reorganizeString(string s) {
            int n = s.size();
            map<char, int> mp;
            for(int i = 0; i < n; i++) mp[s[i]]++;
            priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
            for(auto i : mp) pq.push({i.second, i.first});
            if(pq.top().first > (n+1)/2) return "";
            int i = 0;
            while(!pq.empty()){
                char c = pq.top().second;
                int j = pq.top().first;
                pq.pop();
                while(j > 0 && i < n){ s[i] = c; i += 2; j--; }
                if(i >= n){
                    i = 1;
                    while(j > 0 && i < n){ s[i] = c; i += 2; j--; }
                }
            }
            return s;
        }
    };