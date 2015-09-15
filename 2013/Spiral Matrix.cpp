class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int row = matrix.size();
        if(row == 0) return ret;
        int col = matrix[0].size();
        if(col == 0) return ret;
        int r =1, c =1;
        while(r <= row/2 && c <= col/2)
        {
            //up line
            for(int i=c-1; i<col-c; i++)
                ret.push_back(matrix[r-1][i]);
            //right line
            for(int i=r-1; i<row-r; i++)
                ret.push_back(matrix[i][col-c]);
            //bottom lne
            for(int i=col-c; i>=c; i--)
                ret.push_back(matrix[row-r][i]);
            //left line
            for(int i=row-r; i>=r; i--)
                ret.push_back(matrix[i][c-1]);
            r++;    c++;
        }
        if(col%2 && row > col)
        {
            for(int i=r-1; i<=row-r; i++)
                ret.push_back(matrix[i][c-1]);         
        }
        if(row%2 && col >= row)
        {
            for(int i=c-1; i<=col-c; i++)
                ret.push_back(matrix[r-1][i]);
        }    
        return ret;
    }
};