class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ans;
        vector<int> row1(1,1), row2(2,1);
        if(numRows <=0) return ans;
        if(numRows >= 1) ans.push_back(row1);
        if(numRows >= 2) ans.push_back(row2);
        int index = 2;
        while(++index <= numRows)
        {
            vector<int> row(index,1);
            for(int i=1;i<index-1;i++)
            {                
                row[i] = ans[index-2][i-1] + ans[index-2][i];
                
            }
            ans.push_back(row);
        }
        return ans;
    }
};