class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            set<int> rows, columns;
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[i].size(); j++){
                    if(matrix[i][j] == 0){
                        rows.insert(i);
                        columns.insert(j);
                    }
                }
            }
            for(auto i : rows){
                for(int j = 0; j < matrix[i].size(); j++) matrix[i][j] = 0;
            }
            for(auto i : columns){
                for(int j = 0; j < matrix.size(); j++) matrix[j][i] = 0;
            }
        }
    };