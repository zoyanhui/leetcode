class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int barIndex=0;
        while(A[barIndex] == 0) barIndex++;
        int curMax = A[barIndex];
        barIndex++;
        int plusTrap = 0;
        vector<int> trap;
        
        while(barIndex < n)
        {            
            if(A[barIndex] >= curMax)
            {
                for(int i=0; i<trap.size(); i++)
                    plusTrap += trap[i];
                trap.clear();
                
                curMax = A[barIndex];
            }
            else
            {
                trap.push_back(curMax-A[barIndex]);
            }
            barIndex++;
        }
        int min = INT_MAX;
        for(int i= trap.size()-1; i>=0; i--)
        {
            if(trap[i] < min) min = trap[i];
            else
                plusTrap += trap[i] - min;
        }
        return plusTrap;
    }
};