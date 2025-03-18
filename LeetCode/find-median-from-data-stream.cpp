class MedianFinder {
    public:
        MedianFinder() {
    
        }
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        void addNum(int num) {
            if(left.empty()) left.push(num);
            else if(num < left.top()){
                if(left.size() > right.size()){
                    int t = left.top();
                    left.pop();
                    right.push(t);
                }
                left.push(num); 
            }
            else if(right.empty()) right.push(num);
            else{
                if(left.size() > right.size()){
                    right.push(num);
                }
                else{
                    int t = right.top();
                    right.pop();
                    left.push(min(t, num));
                    right.push(max(t, num));
                }
            }
        }
        
        double findMedian() {
            if(left.size() == right.size()) 
                return (left.top() + right.top())/2.0;
            return 1.0*left.top();
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */