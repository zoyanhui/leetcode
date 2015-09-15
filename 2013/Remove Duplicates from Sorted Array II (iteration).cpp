//iteration method
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return 0;
        bool noDup = true;
        int repIndex = -1;
        for(int i=1; i<n; i++)
        {
            if(A[i] == A[i-1])
            {
                if(noDup)
                {
                    noDup = false;
                    if(repIndex > 0 && repIndex < i)
                    {
                        A[repIndex++] = A[i];
                    }
                }
                else
                {
                    if(repIndex < 0)
                        repIndex = i;                    
                }
            }
            else
            {
                if(repIndex > 0 && repIndex < i)
                {
                    A[repIndex++] = A[i];
                }
                noDup = true;
            }
        }
        if(repIndex < 0)
            return n;
        else 
        {
            
            return repIndex;
        }
            
    }
};