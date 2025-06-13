class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] >= 97 && s[i] <= 122) ss.push_back(s[i] - 97 + 65);
            else if((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90)) ss.push_back(s[i]);
        }
        // cout<<ss;
        int l = ss.size() - 1, r = 0;
        while(l > r){
            if(ss[l] != ss[r]) return false;
            l--, r++;
        }
        return true;
    }
};