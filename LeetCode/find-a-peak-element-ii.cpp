// this is o(m*n) as we are going to first larger element, so not optimised
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), l = 0, r = 0, df[] = {0, -1, 0, 1, 0};
        while(l < m && l >= 0 && r < n && r >= 0){
            bool flg = 1;
            int nl = l, nr = r;
            for(int i = 0; i < 4; i++){
                nl = l + df[i], nr = r + df[i+1];
                if(nl < 0 || nr < 0 || nl >= m || nr >= n) continue;
                if(mat[nl][nr] > mat[l][r]){ flg = 0; break; }
            }
            if(flg) return {l, r};
            l = nl, r = nr;
        }
        return {0, 0};
    }
};
//this is o(n*logm), logic is basically finding max element of row and then traversing acc
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), l = 0, r = m;
        while(l <= r){
            int mid = (r-l)/2 + l, mx = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            bool left = (mid == 0) || (mat[mid-1][mx] < mat[mid][mx]), right = (mid == m-1) || (mat[mid+1][mx] < mat[mid][mx]);
            if(left && right) return {mid, mx};
            if(right) r = mid - 1;
            else l = mid + 1;
        }
        return {0, 0};
    }
};