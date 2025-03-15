class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> ans;
            stack<int> s;
            vector<int> v;
            for(int i = 0; i < intervals.size(); i++){
                if(s.empty()){
                    s.push(intervals[i][1]); 
                    v.push_back(intervals[i][0]); 
                    v.push_back(intervals[i][1]);
                }
                else{
                    if(s.top() >= intervals[i][0]){
                        if(intervals[i][1] >= s.top()){
                            s.pop();
                            s.push(intervals[i][1]);
                            v.pop_back();
                            v.push_back(intervals[i][1]);
                        }
                        else continue;
                    }
                    else{
                        ans.push_back(v);
                        v.clear();
                        while(!s.empty()) s.pop();
                        s.push(intervals[i][1]); 
                        v.push_back(intervals[i][0]); 
                        v.push_back(intervals[i][1]);
                    }
                }
            }
            if(!v.empty()) ans.push_back(v);
            return ans;
        }
    };