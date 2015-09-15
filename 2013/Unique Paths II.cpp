class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = obstacleGrid.size();
        if(row == 0) return 0;
        int col = obstacleGrid[0].size();
        if(col == 0) return 0;
        
        vector<vector<int> > ret(row, vector<int>(col, 0));
        if(obstacleGrid[0][0] == 1) ret[0][0] = 0 ;
        else    ret[0][0] = 1;
        for(int i=1; i< col; i++)
        {
            if(obstacleGrid[0][i] == 1) ret[0][i] = 0;
            else    ret[0][i] = ret[0][i-1];
        }
        for(int i=1; i< row; i++)
        {
            if(obstacleGrid[i][0] == 1) ret[i][0] = 0;
            else    ret[i][0] = ret[i-1][0];
        }
        
        for(int i =1; i< row; i++)
        {
            for(int j=1; j < col; j++)
            {
                if(obstacleGrid[i][j] == 1) ret[i][j] = 0;
                else ret[i][j] = ret[i-1][j] + ret[i][j-1];
            }
        }
        return ret[row-1][col-1];
    }
};