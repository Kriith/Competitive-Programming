class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> s;
            int n = heights.size(), area = -1;
            vector<int> nsel(n, -1), nser(n, n);
            for(int i = 0; i < n; i++){
                while(!s.empty() && heights[i] <= heights[s.top()]) s.pop();
                if(!s.empty()) nsel[i] = s.top();
                s.push(i);
            }
            while(!s.empty()) s.pop();
            for(int i = n - 1; i >= 0; i--){
                while(!s.empty() && heights[i] <= heights[s.top()]) s.pop();
                if(!s.empty()) nser[i] = s.top();
                s.push(i);
            }
            for(int i = 0; i < n; i++) area = max(area, (nser[i] - nsel[i] - 1)*heights[i]);
            return area;
        }
    };