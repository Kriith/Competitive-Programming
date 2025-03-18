class Solution {
    public:
    
        struct cmp{
            bool operator()(pair<int, int> p1, pair<int, int> p2){
                if(p1.second == p2.second) return p1.first < p2.first;
                return p1.second > p2.second;
            }
        };
    
        vector<int> frequencySort(vector<int>& nums) {
            int n = nums.size();
            map<int, int> mp;
            for(int i = 0; i < n; i++) mp[nums[i]]++;
            priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
            for(auto i : mp){
                pq.push({i.first, i.second});
                cout<<i.first<<' '<<i.second<<endl;
            }
            for(int i = 0; i < n; i++){
                int j = pq.top().second, k = pq.top().first;
                cout<<j<<' '<<k<<endl;
                while(j--) nums[i++] = k;
                i--;
                pq.pop();
            }
            return nums;
        }
    };