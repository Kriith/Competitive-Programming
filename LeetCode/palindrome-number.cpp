class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int t = (int)log10(x), l = (int)pow(10, t), r = 10;
        while(l >= r){
            int left = ((x - x%l)/l)%10, right = (x%r)/(r/10);
            // cout<<l<<' '<<left<<' '<<r<<' '<<right<<endl;
            if(left != right) return false;
            l /= 10, r *= 10;
        }
        return true;
    }
};