class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if(m <= 1 || n<= 1) return 1;
       //return uniquePaths(m-1, n) + uniquePaths(m, n-1); // this method will exceed time limit
       
       vector<vector<int> > ret(m+1, vector<int>(n+1, 1));
       
       for(int i=2; i<=m; i++)
       {
           for(int j=2; j <=n; j++)
           {
               ret[i][j] = ret[i-1][j] + ret[i][j-1];
           }
       }
       return ret[m][n];
    }
};