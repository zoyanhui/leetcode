//divide Array by first element(A[0]), and then linear search: worst time O(n)
//average time : n/2 : O(n)

class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0) return -1;
        if(A[0] == target) return 0;
        else if(A[0] > target)
        {
            int i;
            for(i =n-1; i>0 && A[i-1] < A [i]; i--)
            {
                if(A[i] == target)
                {
                    return i; 
                }
            }
            if(A[i] == target) return i;
        }
        else
        {
            for(int i =0; i<n-1 && A[i+1] > A [i]; i++)
            {
                if(A[i+1] == target)
                {
                    return i+1; 
                }
            }
        }
        return -1;
    }
};