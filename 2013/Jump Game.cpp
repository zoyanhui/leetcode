class Solution {
public:
    bool canJump(int A[], int n) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0) return false;
        if(n == 1) return true;
        int curMax = A[0];
        for(int i=1; i<n && i<=curMax; i++)
        {
            if(curMax >= n-1) break;
            curMax = (A[i]+i) > curMax ? (A[i]+i) : curMax;
            
        }
        if(curMax >= n-1) return true;
        else 
            return false;
    }
};