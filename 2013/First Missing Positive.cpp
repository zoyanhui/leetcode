#define NEVER_DIS_NUM  2000
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return 1;
        int jumpIndex = -1;
        for(int i=0; i<n; i++)
        {
            if(A[i] == NEVER_DIS_NUM) i++;
            jumpIndex = A[i];
            
            while(jumpIndex>0 && jumpIndex <=n)
            {
                int temp = A[jumpIndex-1];
                A[jumpIndex-1] = NEVER_DIS_NUM;
                jumpIndex = temp;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(A[i] != NEVER_DIS_NUM) return i+1;
        }
        return n+1;
    }
};