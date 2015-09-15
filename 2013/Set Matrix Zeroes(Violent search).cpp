class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if(row <= 0) return;
        int col = matrix[0].size();
        if(col <= 0) return;
        vector<vector<bool> > flag(row, vector<bool>(col, false));
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(matrix[i][j] ==0)
                {
                    for(int k=0; k<col; k++)
                    {
                        flag[i][k] = true;
                    }
                    for(int k=0; k<row; k++)
                    {
                        flag[k][j] = true;
                    }                    
                }
            }
        }
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(flag[i][j]) 
                    matrix[i][j] = 0;
            }
        }
        
    }
};