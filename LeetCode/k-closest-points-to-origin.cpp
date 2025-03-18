class Solution {
    public:
        
        struct cmp{
            bool operator()(vector<int> v1, vector<int> v2){
                return ((v1[0]*v1[0] + v1[1]*v1[1]) > (v2[0]*v2[0] + v2[1]*v2[1]));
            }
        };
    
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            int n = points.size();
            priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
            for(int i = 0; i < n; i++){
                pq.push(points[i]);
            }
            vector<vector<int>> ans;
            for(int i = 0; i < k; i++){
                ans.push_back(pq.top());
                pq.pop();
            }
            return ans;
        }
    };