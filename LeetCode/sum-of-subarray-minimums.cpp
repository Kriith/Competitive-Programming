class Solution {
    public:
        int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size(); 
            vector<int> nse(n, n), psee(n, -1);
            stack<int> st;
            for(int i = 0; i < n; i++){
                while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
                if(!st.empty()) psee[i] = st.top();
                st.push(i);
            }
            while(!st.empty()) st.pop();
            for(int i = n - 1; i >= 0; i--){
                while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
                if(!st.empty()) nse[i] = st.top();
                st.push(i);
            }
            const int mod = 1e9+7;
            int sum = 0;
            for(int i = 0; i < n; i++)
                sum = (sum + (1LL*(nse[i] - i)*(i - psee[i])*arr[i])%mod)%mod;
            return sum;
        }
    };