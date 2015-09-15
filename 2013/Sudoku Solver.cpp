class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dotRows, dotCols;
        for(int i=0; i< tR; i++)
        {
            for(int j=0; j<tC; j++)
            {
                if(board[i][j] == '.')
                {
                    dotRows.push_back(i);
                    dotCols.push_back(j);
                }                
            }
        }
        int totalBlank = dotRows.size();
        int curBlank = 0;
        if(solve(board, dotRows, dotCols, totalBlank, 0))
            return;
        else return;
        
    }
private:
    const int tR =9 ;
    const int tC = 9;
    bool solve(vector<vector<char> > &board, vector<int> &dotRows, vector<int> &dotCols, const int totalBlank, int curBlank)
    {
        if(curBlank == totalBlank) return true;
        for(int i='1'; i<='9'; i++)
        {
            if(checkValid(board, dotRows[curBlank], dotCols[curBlank], i))
            {
                board[dotRows[curBlank]][dotCols[curBlank]] = i;
                if(solve(board, dotRows, dotCols, totalBlank, curBlank+1)) return true;
                board[dotRows[curBlank]][dotCols[curBlank]] = '.';
            }
        }
        return false;
    }
    bool checkValid(vector<vector<char> > &board, int r, int c, char value)
    {
        for(int i = 0; i< tR; i++)
            if(board[i][c] != '.' && board[i][c] == value) return false;
        for(int i = 0; i< tC; i++)
            if(board[r][i] != '.' && board[r][i] == value) return false;   
        int blockR = r/3, blockC = c/3;
        for(int i=blockR * 3; i< (blockR+1) *3; i++)
        {
            for(int j=blockC * 3; j< (blockC+1) *3; j++)
            {
                if(board[i][j] != '.' && board[i][j] == value) return false; 
            }
        }
        return true;
    }
};