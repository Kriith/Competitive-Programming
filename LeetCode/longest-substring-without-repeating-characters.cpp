class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool> mp;
        int n = s.size(), ans = 1;
        if(n == 0) return 0;
        mp[s[0]] = 1;
        for(int l = 0, r = 1; r < n; r++){
            while(mp[s[r]]){
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]] = 1;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};