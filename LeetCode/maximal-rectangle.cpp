class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int area = 0;
            vector<int> v(matrix[0].size(), 0);
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[i].size(); j++){
                    if(matrix[i][j] == '1') v[j]++;
                    else v[j] = 0;
                }
                stack<int> s;
                vector<int> l(matrix[i].size(), -1), r(matrix[i].size(), matrix[i].size());
                for(int j = 0; j < matrix[i].size(); j++){
                    while(!s.empty() && v[j] <= v[s.top()]) s.pop();
                    if(!s.empty()) l[j] = s.top();
                    s.push(j);
                }
                while(!s.empty()) s.pop();
                for(int j = matrix[i].size() - 1; j >= 0; j--){
                    while(!s.empty() && v[j] <= v[s.top()]) s.pop();
                    if(!s.empty()) r[j] = s.top();
                    s.push(j);
                }
                for(int j = 0; j < matrix[i].size(); j++)
                    area = max(area, (r[j] - l[j] - 1)*v[j]);
            }
            return area;
        }
    };