class Solution {
    public:
        string removeKdigits(string num, int k) {
            // if(k >= num.size()) return "0";
            stack<char> s;
            int n = num.size();
            for(int i = 0; i < n; i++){
                while(!s.empty() && k > 0 && s.top() > num[i]){
                    s.pop(); 
                    k--;
                }
                s.push(num[i]);
            }
            while(!s.empty() && k > 0){ s.pop(); k--; }
            string ans = "";
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
            while(ans.size() > 1 && *ans.rbegin() == '0') ans.pop_back();
            reverse(ans.begin(), ans.end());
            if(ans == "") ans = "0";
            return ans;
        }
    };