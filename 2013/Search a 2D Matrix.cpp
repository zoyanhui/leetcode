//excute binary search in columns[0] to find row, 
//and then binary search in this row to find "target"
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if(row <= 0) return false;
        int col = matrix[0].size();
        if(col <= 0) return false;
        
        int cRow = rowBinary(matrix, target, 0, row-1);
        if(cRow < 0) cRow = 0;
        if(cRow >= row) cRow = row-1;
        vector<int> array = matrix[cRow];
        if(array[0] == target) return true;
        return binarySearch(array, target, 0, col-1);
        
    }
private:
    int rowBinary(const vector<vector<int> > &matrix, const int target, int up, int down)
    {
        
        if(down <= up) 
        {
            if(down > 0)
            {
                if(matrix[down][0] > target) 
                    return down -1;
                else
                    return down;
            }
            else 
                return 0;
            
        }
        int mid = up + (down - up)/2;
        if(matrix[mid][0] == target)
            return mid;
        else if(matrix[mid][0] < target)
            return rowBinary(matrix, target, mid+1, down);            
        else
            return rowBinary(matrix, target, up, mid-1);
    }
    bool binarySearch(const vector<int> &array, const int target, int left, int right)
    {
        if(left > right) return false;
        int mid = left + (right -left)/2;
        if(array[mid] == target)
            return true;
        else if(array[mid] < target)    
            return binarySearch(array, target, mid+1, right);
        else
            return binarySearch(array, target, left, mid-1);
    }
};