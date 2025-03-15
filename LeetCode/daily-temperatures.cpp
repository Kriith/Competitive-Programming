class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            stack<int> s;
            vector<int> ans(temperatures.size(), 0);
            for(int i = temperatures.size() - 1; i >= 0; i--){
                while(s.size() > 0 && temperatures[s.top()] <= temperatures[i]) s.pop();
                if(s.size() > 0) ans[i] = s.top() - i;
                s.push(i);
            }
            return ans;
        }
    };