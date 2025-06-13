class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0, cnt = 0;
        vector<int> mp(26, 0);
        for(int l = 0, r = 0; r < n; r++){
            mp[s[r] - 65]++;
            cnt = max(cnt, mp[s[r] - 65]);
            while(r - l + 1 - cnt > k) mp[s[l] - 65]--, l++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};