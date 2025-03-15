class Solution {
    public:
        bool isPerfectSquare(int num) {
            int l = 1, r = num;
            while(l <= r){
                int m = (r - l)/2 + l;
                if(1LL*m*m == num) return true; 
                else if(1LL*m*m < num) l = m + 1;
                else r = m - 1;
            }
            return false;
        }
    };