// map approach, to use priority queue, instead of sorting t, use pq there
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> ans(k);
            map<int, int> mp;
            for(int i = 0; i < n; i++) mp[nums[i]]++;
            vector<pair<int, int>> t;
            for(auto i : mp){
                t.push_back({i.second, i.first});
            }
            sort(t.begin(), t.end(), greater<>());
            for(int i = 0; i < k; i++){
                ans[i] = t[i].second;
            }
            return ans;
        }
    };