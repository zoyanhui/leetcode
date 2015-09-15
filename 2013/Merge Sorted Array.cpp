class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = m+n-1;
        int aindex = m-1, bindex = n-1;
        while(aindex>=0 && bindex >=0)
        {
            if(A[aindex] > B[bindex])            
                A[index--] = A[aindex--];        
            else
                A[index--] = B[bindex--];
        }
        while(aindex>=0)       
            A[index--] = A[aindex--];
         while(bindex>=0)
             A[index--] = B[bindex--];
    }
};