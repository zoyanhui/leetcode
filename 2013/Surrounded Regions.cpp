class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        mark.clear();
        int row = board.size();
        if(row <=0) return;
        int col = board[0].size();
        if(col <=0 ) return;
        for(int i = 0; i< row; i++)
        {
            vector<bool> v(col,false);
            mark.push_back(v);
        }
        walkBoard(board, row, col);
    }
private:
    void walkBoard(vector<vector<char>> &board, int row, int col)
    {
        for(int i=0; i < row; i++)
        {
            for(int j=0; j < col; j++)
            {
                vector<int> rowX;
                vector<int> colY;
                if(board[i][j] == 'O' && !mark[i][j])
                {
                    mark[i][j] = true;
                    rowX.clear();
                    colY.clear();
                    rowX.push_back(i);
                    colY.push_back(j);
                    int rX, cY, n=0;
                    bool isSurr = true;
                    while(n<rowX.size())
                    {
                        rX = rowX[n];
                        cY = colY[n];
                        if(rX <= 0 || rX >= row-1 || cY <=0 || cY >= col-1)
                        {
                            isSurr = false;
                        }
                        for(int k =0; k < 4; k++)
                        {
                            int newX = rX+dx[k], newY = cY+dy[k];
                            if(newX < 0 || newX >= row || newY < 0 || newY >= col)
                                continue;
                            if(board[newX][newY] == 'O' && !mark[newX][newY])
                            {
                                mark[newX][newY] = true;
                                rowX.push_back(newX);
                                colY.push_back(newY);
                                
                            }
                        }
                        n++;
                    }
                    if(isSurr)
                    {
                        for(int k=0; k<rowX.size(); k++)
                        {
                            board[rowX[k]][colY[k]] = 'X';
                        }
                    }
                    
                }
                
                
            }
        }
    }
    vector<vector<bool>> mark;
    int dx[4] = {0, 0 ,-1, 1};  // (dx[i],dy[i]) which consists of dx and dy, is direction of left
    int dy[4] = {-1, 1, 0, 0};  // right, up and down
};