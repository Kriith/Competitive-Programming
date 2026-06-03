class StockSpanner {
public:
    stack<pair<int, int>> st;
    int prev, prevans;
    StockSpanner() {
        while(!st.empty()) st.pop();
        prev = prevans = 0;
    }
    
    int next(int price) {
        if(price < prev){
            st.push({prev, prevans});
            prev = price, prevans = 1;
            return 1;
        }
        int ans = prevans + 1;
        while(!st.empty() && price >= st.top().first){
            ans += st.top().second;
            st.pop();
        }
        prev = price, prevans = ans;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */