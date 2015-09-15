//DFS
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = board.size();
        if(row <= 0) return false;
        int col = board[0].size();
        if(col <= 0) return false;
        int len = word.length();
        if(len <= 0) return true;
        if(row * col < len) return false;
        
        vector<vector<bool> > isWalk(row, vector<bool>(col, false));
        for(int i =0; i < row; i++)
        {
            for( int j =0; j < col; j++)
            {
                if(board[i][j] == word[0])
                {
                    
                    if(searchDFS(board, word, len, 0, isWalk, row, col, i, j)) return true;
                } 
                
            }
        }
        return false;
    }
private:
    bool searchDFS(vector<vector<char> > &board, const string &word, const int len, int strIndex, vector<vector<bool> > &isWalk, const int row, const int col, int r, int c)
    {
        if(r<0 || r>=row || c<0 || c>=col) return false;
        if(board[r][c] != word[strIndex])
        {
            isWalk[r][c] = false;
            return false;
        } 
        isWalk[r][c] = true;
        if(strIndex == len -1) return true;
        if(r+1<row && !isWalk[r+1][c] && searchDFS(board, word, len, strIndex+1, isWalk, row, col, r+1, c)) return true;
        if(r-1>=0 && !isWalk[r-1][c] && searchDFS(board, word, len, strIndex+1, isWalk, row, col, r-1, c)) return true;
        if(c+1<col && !isWalk[r][c+1] && searchDFS(board, word, len, strIndex+1, isWalk, row, col, r, c+1)) return true;
        if(c-1>=0 && !isWalk[r][c-1] && searchDFS(board, word, len, strIndex+1, isWalk, row, col, r, c-1)) return true;
        
        isWalk[r][c] = false;
        return false;
    }
};