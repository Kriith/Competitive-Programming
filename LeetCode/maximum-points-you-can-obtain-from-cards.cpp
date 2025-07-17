class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), m = accumulate(cardPoints.begin(), cardPoints.end() - k, 0), ans = m;
        for(int i = n - k; i < n; i++){
            m += cardPoints[i] - cardPoints[i - n + k];
            ans = min(ans, m);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - ans;
    }
};