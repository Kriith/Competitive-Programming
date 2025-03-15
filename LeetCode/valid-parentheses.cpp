class Solution {
    public:
        bool isValid(string s) {
            map<char, int> mp;
            mp['('] = -1; mp[')'] = 1;
            mp['{'] = -2; mp['}'] = 2;
            mp['['] = -3; mp[']'] = 3;
            stack<char> st;
            for(int i = 0; i < s.size(); i++){
                if(!st.empty() && mp[st.top()] > 0) return false;
                if(!st.empty() && mp[st.top()] == (-1*mp[s[i]])) st.pop();
                else st.push(s[i]);
            }
            if(st.empty()) return true;
            else return false;
        }
    };