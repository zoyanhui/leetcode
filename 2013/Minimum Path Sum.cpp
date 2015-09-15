class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        if(col == 0) return 0;
        
        vector<vector<int> > dis(row, vector<int>(col, INT_MAX));
        dis[0][0] = grid[0][0];
        for(int i=1; i< col; i++) dis[0][i] = dis[0][i-1] + grid[0][i];
        for(int i=1; i< row; i++) dis[i][0] = dis[i-1][0] + grid[i][0];
        
        for(int i =1; i< row; i++)
        {
            for(int j=1; j < col; j++)
            {
                
                int temp = (dis[i-1][j] > dis[i][j-1] ? dis[i][j-1] : dis[i-1][j]) + grid[i][j];
                dis[i][j] = dis[i][j] > temp ? temp : dis[i][j];
            }
        }
        return dis[row-1][col-1];
    }
};