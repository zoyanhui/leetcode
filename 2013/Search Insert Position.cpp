class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n-1;
        if(n ==0) return 0;
        if(n==1) return target > A[0] ? 1 : 0;
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(A[mid] == target) return mid;
            else if(A[mid] < target) left = mid+1;
            else right = mid-1;
        }
        if(A[left] < target)
        {
            return left+1;
        }
        else if(A[left] == target)
            return left;
        else
        {
            return left;
        }
    }
};