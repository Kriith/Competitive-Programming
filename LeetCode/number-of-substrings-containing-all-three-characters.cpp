class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), cnt[3] = {-1, -1, -1}, ans = 0;
        for(int i = 0; i < n; i++){
            cnt[s[i] - 'a'] = i;
            ans += *min_element(cnt, cnt + 3) + 1;
        }
        return ans;
    }
};

/*
Explanation: Initialised to -1, so if no element has not yet been found it will add 0 to ans
Take the example "bbccbac"
So the answer will get incremented first when it reaches the first a
Min of the cnt will be 3
min + 1 = no. of elements till that number
that is equal to number of substrings from the start till that index
basically choosing 3rd index and nothing before it
then choosing 2nd index and nothing before it
and so on till the 0th index element.
*/