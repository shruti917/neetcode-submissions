class Solution {
public:
vector<pair<int,int>>dist={{-1,0},{1,0},{0,-1},{0,1}};
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>issafe(n,vector<bool>(m,false));

       
for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                safe(board, i, 0, issafe);

            if (board[i][m-1] == 'O')
                safe(board, i, m-1, issafe);
        }


         for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                safe(board, 0, j, issafe);

            if (board[n-1][j] == 'O')
                safe(board, n-1, j, issafe);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !issafe[i][j]) board[i][j]='X';
            }
        }
    }

    void safe(vector<vector<char>>& board,int r,int c, vector<vector<bool>>&issafe){
         int n=board.size();
        int m=board[0].size();

        if(r<0|| r>=n|| c<0|| c>=m|| board[r][c]=='X' )return;

        if (board[r][c] != 'O' || issafe[r][c])
            return;

        
        issafe[r][c] = true;

        for(int i=0;i<4;i++){
            int k=r+ dist[i].first;
            int l= c+dist[i].second;
 safe(board, k, l, issafe);
        }
    }
};
