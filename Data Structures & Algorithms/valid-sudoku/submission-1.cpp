class Solution {
public:


bool is_valid(vector<vector<char>>& board, int row, int col) {
    unordered_set<char> st;

    for(int i = row; i < row + 3; i++) {
        for(int j = col; j < col + 3; j++) {
            if(board[i][j] == '.') continue;

            if(st.count(board[i][j]))
                return false;

            st.insert(board[i][j]);
        }
    }
    return true;
}


    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n= board.size();


        for(int row=0;row< n;row++){
            unordered_set<char> st;
            for(int i=0;i<n;i++){
                if(board[row][i]=='.') continue;
                if(st.count(board[row][i])) return false;
                st.insert(board[row][i]);
            }
        }

            for(int row=0;row< n;row++){
            unordered_set<char> st;
            for(int i=0;i<n;i++){
                if(board[i][row]=='.') continue;
                if(st.count(board[i][row])) return false;
                st.insert(board[i][row]);
            }
        }


        // for(int row=0;row< n;row++){
        //     unordered_set<char> st1,st2;
        //     for(int i=0;i<n;i++){
        //         if(st1.count(board[i][row]) || st2.count(board[row][i]) ) return false;
        //         else if(board[i][row]!='.') st1.insert(board[i][row]);
        //        else if(board[row][i]!='.') st2.insert(board[row][i]);
                
        //     }
        // }


for(int i = 0; i < n; i += 3) {
    for(int j = 0; j < n; j += 3) {
        if(!is_valid(board, i, j))
            return false;
    }
}



return true;
        
    }
};
