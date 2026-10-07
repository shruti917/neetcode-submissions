class Solution {
public:
set<pair<int,int>>part;



    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
              if(dfs(board,word,i,j,0))  return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& b, string word,int r,int c,int i){
    if(i==word.length())return true;
    int row=b.size();
    int col= b[0].size();


    if(r<0|| c<0|| r>= row|| c>= col ||b[r][c]!= word[i]||part.count({r,c}) ) return false;

    part.insert({r,c});
    bool res=dfs(b,word,r+1,c,i+1)||
    dfs(b,word,r,c+1,i+1)||
    dfs(b,word,r-1,c,i+1)||
    dfs(b,word,r,c-1,i+1);
part.erase({r,c});

    return res;
}
};
