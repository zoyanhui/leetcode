class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int zeros = 0, ones = 0, twos = 0;
        for(int i=0; i<n; i++)
        {
            switch(A[i])
            {
                case 0:
                    zeros++;
                    break;
                case 1:
                    ones++;
                    break;
                case 2:
                    twos++;
                    break;
            }            
        }
        int k=0;
        for(; k<zeros; k++)
        {
            A[k] = 0; 
        }
        for(k=0; k<ones; k++)
        {
            A[k+zeros] = 1; 
        }
        for(k=0; k<twos; k++)
        {
            A[k+zeros+ones] = 2; 
        }
    }
};