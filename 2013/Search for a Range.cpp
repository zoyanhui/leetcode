class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(2, -1);
        if(n <= 0 ) return ret;        
        
       ret[0] = searchIndex(A, 0, n-1, target, true, n);
       ret[1] = searchIndex(A, 0, n-1, target, false, n);
        
        return ret;
    }
private:
    int searchIndex(const int A[], int left, int right, const int target, bool searchLeft, const int n)
    {
        
        while(left <= right)
        {
            int mid = left + (right - left) /2;
            if(A[mid] == target)
            {
                if(searchLeft)
                {
                    if(mid == 0 || A[mid-1] < target)
                        return mid;
                    else
                        right = mid -1;
                }
                else
                {                    
                    if(mid == n-1 || A[mid+1] > target)
                        return mid;
                    else
                        left = mid+1;
                }
            }
            else if(A[mid] < target)
            {
                left = mid+1;
            }
            else
                right = mid-1;                
            
        }
        return -1;
    }
};