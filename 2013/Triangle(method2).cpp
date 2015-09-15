//O(n) extra space
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = triangle.size();
        if(row < 2) return triangle[0][0];
        vector<int> ans(row,0);
        for(int j=0;j<triangle[row-1].size();j++)
            ans[j] = triangle[row-1][j];
        for(int i = row-2; i>=0; i--)
        {
            for(int j = 0;j<triangle[i].size();j++)
            {
                ans[j] = triangle[i][j] + (ans[j] < ans[j+1] ? ans [j] : ans[j+1]); 
            }
        }
        return ans[0];
    }
};