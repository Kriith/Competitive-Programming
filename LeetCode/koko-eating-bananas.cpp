class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int ans = 0, l = 1, r = 1e9;
            while(l <= r){
                int m = (r - l)/2 + l, t = 0;
                for(int i = 0; i < piles.size(); i++){
                    if(t > h) break;
                    if(piles[i] <= m) t++;
                    else t += (int)ceil(1.0*piles[i]/m);
                }
                if(t <= h){ ans = m; r = m - 1; }
                else l = m + 1;
            }   
            return ans;
        }
    };