class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret(2, -1);
        if(n <= 0 ) return ret;        
        
        int sIndex = searchIndex(A, 0, n-1, target);
        ret[0] = ret[1] = sIndex;
        int lIndex = sIndex, rIndex = sIndex;
        
        while(lIndex != -1 && lIndex >=0)
        {
            ret[0] = lIndex;
            int left = 0, right = lIndex -1;
            lIndex = searchIndex(A, left, right, target);
            
        }
        while(rIndex != -1 && rIndex < n)
        {
            ret[1] = rIndex;
            int left = rIndex + 1, right = n-1;
            rIndex = searchIndex(A, left, right, target);
            
        }
        return ret;
    }
private:
    int searchIndex(const int A[], int left, int right, const int target)
    {
        
        while(left <= right)
        {
            int mid = left + (right - left) /2;
            if(A[mid] == target)
            {
                return mid;
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