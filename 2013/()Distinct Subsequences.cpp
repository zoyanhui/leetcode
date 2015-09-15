class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lenS = S.length();
        int lenT = T.length();
        if(lenS < lenT) return 0;
        
        vector<vector<int>> dp(lenS+1, vector<int>(lenT+1,0));
        for(int i =0; i<lenS; i++)
        {
            if(S[i] == T[0])
                dp[i+1][1] = dp[i][1] + 1;
            else dp[i+1][1] = dp[i][1];
        }
        for(int i =1; i<lenS; i++)
        {
            for(int j =1; j<lenT; j++)
            {
                if(S[i] == T[j])
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                else
                    dp[i+1][j+1] = dp[i][j+1];
            }
        }
        return dp[lenS][lenT];
    }
};