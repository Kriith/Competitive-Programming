//Z-Function
class Solution {
public:
    int strStr(string haystack, string needle) {
        string s = needle + ',' + haystack;
        int n = needle.size(), h = haystack.size(), ss = s.size();
        vector<int> z(ss+1, 0);
        int l = 0, r = 0;
        for(int i = 0; i < ss; i++){
            if(i < r) z[i] = min(r - i, z[i-l]);
            while(i + z[i] < ss && s[z[i]] == s[i + z[i]]) z[i]++;
            if(i + z[i] > r) l = i, r = z[i] + i;
        }
        for(int i = 0; i < h; i++)
            if(z[i + n + 1] == n) return i;
        return -1;
    }
};

//KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        string s = needle + ',' + haystack;
        int n = s.size();
        vector<int> pi(n, 0);
        for(int i = 1; i < n; i++){
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j]) j = pi[j-1];
            if(s[i] == s[j]) j++;
            pi[i] = j;
        }
        for(int i = 0; i + needle.size() <= haystack.size(); i++){
            if(pi[i + 2*needle.size()] == needle.size()) return i;
        }
        return -1;
    }
};