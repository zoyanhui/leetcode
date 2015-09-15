class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if(row ==0) return;
        int col = matrix[0].size();
        if(col==0) return;
        vector<vector<int> > temp(row, vector<int>(col, 0));
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                temp[j][row-i-1] = matrix[i][j];
            }
        }
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                matrix[i][j] = temp[i][j];
            }
        }
    }
};