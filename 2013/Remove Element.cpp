class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <=0) return 0;
        
        int end = n-1;
        int len = n;
        for(int i=0; i<=end; i++)
        {
            if(A[i] == elem)
            {
                while(A[end] == elem && i<end)
                {
                    end--;  len--;
                } 
                A[i] = A[end];
                end--;
                len--;
            }
        }
        return len;
    }
};