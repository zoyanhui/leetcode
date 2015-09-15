//no extra memory space
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        setDown2Up(triangle);
        int ans = triangle[0][0];
        resetUp2Down(triangle);
        return ans;
    }
private:
    void setDown2Up(vector<vector<int>> &triangle)
    {
        int row = triangle.size();
        for(int i = row -2; i >=0 ;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                triangle[i][j] += triangle[i+1][j] > triangle[i+1][j+1] ? triangle[i+1][j+1]:triangle[i+1][j];
            }
        }
    }
    void resetUp2Down(vector<vector<int>> &triangle)
    {
        int row = triangle.size(); 
        if(row <2) return;
        for(int i = 0; i < row -1 ;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                triangle[i][j] -= triangle[i+1][j] > triangle[i+1][j+1] ? triangle[i+1][j+1]:triangle[i+1][j];
            }
        }
    }
};