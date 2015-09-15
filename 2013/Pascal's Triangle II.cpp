class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if(rowIndex < 0) return ans;
        if(rowIndex >= 0) ans.push_back(1); 
        if(rowIndex >= 1) ans.push_back(1);
        
        for(int i=2;i<=rowIndex;i++)
        {
            int left = 1 ,right;
            for(int j=1; j<i;j++)
            {
                right = ans[j];
                ans[j] = left+right;
                left = right;
            }
            ans.push_back(1);
            
        }
        return ans;
    }
};