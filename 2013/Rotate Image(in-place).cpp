class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if(row ==0) return;
        int col = matrix[0].size();
        if(col==0) return;
        //transposition whole matrix
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //reverse column vector
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col/2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][col-1-j];
                matrix[i][col-1-j] = temp;
            }
        }
    }
};