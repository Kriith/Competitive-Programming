//recursive soln
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n-1), ans = "";
        for(int i = 0; i < s.size();){
            int index = i + 1;
            while(index < s.size() && s[index] == s[i]) index++;
            ans += to_string(index - i) + s[i];
            // s.erase(s.begin() + i + 1, s.begin() + index);
            // s.insert(s.begin() + i, '0' + index - i);
            i = index;
        }
        return ans;
    }
};

//iterative
class Solution {
public:
    string countAndSay(int n) {
        string s = "1", ans = s;
        for(int i = 2; i <= n; i++){
            ans = "";
            for(int i = 0; i < s.size();){
                int index = i + 1;
                while(index < s.size() && s[index] == s[i]) index++;
                ans += to_string(index - i) + s[i];
                // s.erase(s.begin() + i + 1, s.begin() + index);
                // s.insert(s.begin() + i, '0' + index - i);
                i = index;
            }
            s = ans;
        }
        return ans;
    }
};