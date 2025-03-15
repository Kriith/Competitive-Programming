class Solution {
    public:
        int minAddToMakeValid(string s) {
            map<char, int> mp;
            mp['('] = -1, mp[')'] = 1;
            stack<char> st;
            for(int i = 0; i < s.size(); i++){
                if(!st.empty() && mp[st.top()] < 0 && mp[st.top()] == -1*mp[s[i]]) st.pop();
                else st.push(s[i]);
            }
            return st.size();
        }
    };