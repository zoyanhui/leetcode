class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        if(n<=0) return ret;
        const string origin(n,'.');
        vector<vector<bool> > board(n, vector<bool>(n, false));
        vector<string> solution;
        setQueens(0, solution, n, origin, board);
        
        return ret;
    }
private:
    vector<vector<string> > ret;
    
    void setQueens(int k, vector<string> &solution, const int n, const string &origin, vector<vector<bool> > &board)
    {
        //if(k > n-1) return;
        for(int i=0; i<n; i++)
        {            
            if(board[k][i] || !canSetQ(board, k, i, n)) continue;
//change solution every time
            string s = origin;
            s[i] = 'Q';            
            solution.push_back(s);  //change solution every time
            board[k][i] = true;
            if(k == n-1) 
            {
                //setBoard(board, n, solution);
                ret.push_back(solution);
            }                
            else
            {
                setQueens(k+1, solution, n, origin, board);                
            }    
            solution.pop_back();
            board[k][i] = false;
            
        }
    }
    bool canSetQ(vector<vector<bool> > &board, int r, int c, const int n)
    {
        for(int i=0; i<n; i++)
            if(board[r][i]) return false;
        for(int i=0; i<n; i++)
            if(board[i][c]) return false;
        for(int i=r, j=c; i>=0 && j>=0; i--, j--)
            if(board[i][j]) return false;
        for(int i=r, j=c; i<n && j<n; i++, j++)
            if(board[i][j]) return false;
        for(int i=r, j=c; i>=0 && j<n; i--, j++)
            if(board[i][j]) return false;
        for(int i=r, j=c; i<n && j>=0; i++, j--)
            if(board[i][j]) return false;
        return true;
    }
    void setBoard(vector<vector<bool> > &board, const int n, vector<string> &solution)
    {
        solution.clear();
        for(int i=0; i<n; i++)
        {
            string s(n, '.');
            for(int j=0; j<n; j++)
            {
                if(board[i][j])
                {
                    s[j] = 'Q';
                    solution.push_back(s);
                    break;
                }
            }
        }
    }
};