class Solution {
    public:
        bool isNStraightHand(vector<int>& hand, int groupSize) {
            int n = hand.size();
            map<int, int> mp;
            for(int i = 0; i < n; i++) mp[hand[i]]++;
            sort(hand.begin(), hand.end());
            for(int i = 0; i < n; i++){
                if(mp[hand[i]] > 0){
                    for(int j = hand[i]; j < hand[i] + groupSize; j++){
                        if(mp[j] == 0) return false;
                        mp[j]--;
                    }
                }
            }
            return true;
        }
    };