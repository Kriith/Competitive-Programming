class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size(), cnt = 0, starti = -1, start = 0, len = INT_MAX;
        if(m < n) return "";
        vector<int> cnt1(123, 0), cnt2(123, 0);
        for(int i = 0; i < n; i++) cnt1[t[i]]++;
        for(int i = 0; i < m; i++){
            cnt2[s[i]]++;
            //cnt2 should be <= as we have to check for the no. of duplicates
            //eg for 3 a's we need to inc cnt for first 3 a's
            //then if that cnt == n then we check the later part
            if(cnt1[s[i]] > 0 && cnt2[s[i]] <= cnt1[s[i]]) cnt++;
            if(cnt == n){
                while(cnt1[s[start]] == 0 || cnt2[s[start]] > cnt1[s[start]]){
                    if(cnt1[s[start]] > 0) cnt2[s[start]]--;
                    start++;
                }
                int curlen = i - start + 1;
                if(curlen <= len) len = curlen, starti = start;
            }
        }
        if(starti < 0) return "";
        return s.substr(starti, len);
    }
};