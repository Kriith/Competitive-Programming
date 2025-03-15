class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& a) {
            stack<int> s;
            int n = a.size();
            for(int i = 0; i < n; i++){
                if(s.empty() || s.top() < 0 || (s.top()*a[i] > 0)) s.push(a[i]);
                else{
                    while(!s.empty() && s.top()*a[i] < 0 && s.top() < -1*a[i]) s.pop();
                    if(s.empty() || s.top()*a[i] > 0) s.push(a[i]);
                    else if(s.top() == -1*a[i]) s.pop();
                }
            }
            vector<int> ans;
            while(!s.empty()){ ans.push_back(s.top()); s.pop(); }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };