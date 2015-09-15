//iteration method
class Solution {
public:
    int removeDuplicates(int A[], int n) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = -1;
        if(n <=1) return n;
        moveDuplicate(A, n , 1, index, true);
        if(index <0) return n;
        return index;
    }
private:
    void moveDuplicate(int A[], int n, int cur, int &index, bool nod)
    {
        if(cur ==n) return;
        if(A[cur] == A[cur-1])
        {
            if(nod)
            {
                if(index > 0) A[index++] = A[cur]; 
                moveDuplicate(A, n, cur+1, index, false);
            }
            else
            {
                if(index <0) index = cur;
                moveDuplicate(A, n, cur+1, index, false);
            }
        }
        else
        {
            if(index > 0) A[index++] = A[cur]; 
            moveDuplicate(A, n, cur+1, index, true);
        }
    }
};