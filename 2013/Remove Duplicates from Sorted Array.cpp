class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(n <=0) return 0;
        int k = -1;
        for(int i=1; i<n; i++)
        {
            if(A[i] == A[i-1])
            {
                int s = i-1;
                while(i<n && A[i] == A[s]) i++;
                A[++k] = A[s];
            }
            else
            {
                A[++k] = A[i-1];
            }
        }
        if(A[n-1] != A[n-2]) A[++k] = A[n-1];
        return k+1;
    }
};
