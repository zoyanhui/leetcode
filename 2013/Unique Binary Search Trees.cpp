class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <=2) return n;
        vector<int> ans(n+1, 0);
        ans[0] = 1; ans[1] = 1; ans[2] = 2; // suppose n=0, ans be 1, in order to calculate later
        for(int i = 3; i <= n; i++)
        {
            for(int k = 1; k <= i; k++)
            {
                ans[i] += ans[i-k] * ans[k-1]; 
            }
        }
        return ans[n];
    }
};