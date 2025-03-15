class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
            int n = workers.size(), t = tasks.size();
    
            auto check = [&](int m) -> bool{
                int p = pills, ti = 0;
                deque<int> dq;
                for(int i = n - m; i < n; i++){
                    while(ti < t && tasks[ti] <= workers[i] + strength)
                        dq.push_back(tasks[ti++]);
                    if(dq.empty()) return false;
                    if(dq.front() <= workers[i]) dq.pop_front();
                    else if(p > 0){
                        dq.pop_back(); p--;
                    }
                    else return false;
                }
                return true;
            };
    
            int ans = 0, l = 0, r = min(t, n);
            while(l <= r){
                int m = (r - l)/2 + l;
                if(check(m)){ ans = m; l = m + 1; }
                else r = m - 1;
            }
            return ans;
        }
    };