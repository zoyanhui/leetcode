class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return 0;
        int max = A[0], cur = 0;
        for(int i=0; i<n; i++)
        {
            cur += A[i];
            if(cur < 0) cur =0;
            if(cur > max) max = cur;            
        }
        if(max != 0) return max;
        max = A[0];
        for(int i=1; i< n; i++)
        {
            if(A[i] > max) max = A[i];
        }
        return max;
    }
};