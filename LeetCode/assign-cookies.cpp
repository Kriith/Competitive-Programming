class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int> cookie(s.begin(), s.end()), children(g.begin(), g.end());
        int ans = 0;
        while(!cookie.empty() && !children.empty()){
            if(cookie.top() >= children.top()){
                ans++;
                cookie.pop();
            }
            children.pop();
        }
        return ans;
    }
};