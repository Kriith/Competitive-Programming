class FreqStack {
    public:
        map<int, int> freq;
        map<int, stack<int>> st;
        int mx;
        FreqStack() {
            mx = 0;
        }
        
        void push(int val) {
            freq[val]++;
            st[freq[val]].push(val);
            mx = max(mx, freq[val]);
        }
        
        int pop() {
            int t = st[mx].top();
            st[mx].pop();
            freq[t]--;
            if(st[mx].empty()) mx--;
            return t;
        }
    };
    
    /**
     * Your FreqStack object will be instantiated and called as such:
     * FreqStack* obj = new FreqStack();
     * obj->push(val);
     * int param_2 = obj->pop();
     */