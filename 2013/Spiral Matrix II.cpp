class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret(n, vector<int>(n, -1));
        int k = 1, cur = 1;  // k is the num of circle
        while(k <= n/2)
        {
             //up line
            for(int i=k-1; i<n-k; i++)
            {
                ret[k-1][i] = cur++;
            }
            //right lin
            for(int j=k-1; j<n-k; j++)
                ret[j][n-k] = cur++;    
            //bottom lin
            for(int i=n-k; i >= k; i--)
                ret[n-k][i] = cur++;
            //left line
            for(int i=n-k; i>= k; i--)
                ret[i][k-1] = cur++;
            k++;
        }
        if(n%2)
            ret[n/2][n/2] = cur;
       return ret;
    }
};