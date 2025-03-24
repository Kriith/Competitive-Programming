class Solution {
    public:
    
        void dfs(int x, int y, vector<vector<bool>>& marked, vector<vector<char>>& board){
            marked[x][y] = 1;
            // cout<<x<<' '<<y<<endl;
            int m = marked.size(), n = marked[0].size();
            int nx[4] = {0, 0, -1, 1};
            int ny[4] = {-1, 1, 0, 0};
            for(int i = 0; i < 4; i++){
                int nnx = x + nx[i], nny = y + ny[i];
                if(nnx < 0 || nnx >= m || nny < 0 || nny >= n) continue;
                if(!marked[nnx][nny] && board[nnx][nny] == 'O') 
                    dfs(nnx, nny, marked, board);
            }
            return;
        }
    
        void solve(vector<vector<char>>& board) {
            int m = board.size(), n = board[0].size();
            vector<vector<bool>> marked(m, vector<bool>(n, 0));
            for(int i = 0; i < m; i++){
                // cout<<i<<' '<<board[i][0]<<' '<<marked[i][0]<<' '<<board[i][n-1]<<' '<<marked[i][n-1]<<endl;
                if(board[i][0] == 'O' && !marked[i][0])
                    dfs(i, 0, marked, board);
                if(board[i][n-1] == 'O' && !marked[i][n-1])
                    dfs(i, n-1, marked, board);
            }
            for(int i = 0; i < n; i++){
                // cout<<i<<' '<<board[0][i]<<' '<<marked[0][i]<<' '<<board[m-1][i]<<' '<<marked[m-1][i]<<endl;
                if(board[0][i] == 'O' && !marked[0][i])
                    dfs(0, i, marked, board);
                if(board[m-1][i] == 'O' && !marked[m-1][i])
                    dfs(m-1, i, marked, board);
            }
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(board[i][j] == 'O'  && !marked[i][j])
                        board[i][j] = 'X';
                }
            }
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++) cout<<marked[i][j]<<' ';
                cout<<endl;
            }
        }
    };