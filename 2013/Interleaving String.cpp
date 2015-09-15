class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3) return false;
        vector<vector<bool> > dp(len1+1, vector<bool>(len2+1, false)); //dp[0][0] = true; no element from s1 or s2 can consist of a empty s3
        dp[0][0] = true;   //and set it to true for calculation below
        for(int i=0; i<len1; i++)
            dp[i+1][0] = (s1[i] == s3[i]) & dp[i][0];  // all elements from s1 to be s3
        for(int i=0; i<len2; i++)
            dp[0][i+1] = (s2[i] == s3[i]) & dp[0][i];  // all elements from s2 to be s3
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                
                if(s1[i] == s3[i+j+1])
                    dp[i+1][j+1] = dp[i+1][j+1] | dp[i][j+1];
                if(s2[j] == s3[i+j+1])
                    dp[i+1][j+1] = dp[i+1][j+1] | dp[i+1][j];
            }
        }
        return dp[len1][len2];
    }
};