class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1) return 0;
        vector<int> ret(n, n+1);
        vector<bool> canUse(n, true);
        ret[0] = 0;
        int maxReachIndex = 0;
        for(int i=0; i< n && i<= maxReachIndex; i++)
        {
            int oldMax = maxReachIndex;
            if(i+A[i] < maxReachIndex) continue;
            else
            {
                maxReachIndex = i+A[i];
            }
            
            if(!canUse[i]) continue;
            for(int j=oldMax+1; j <n && j<=maxReachIndex; j++)
            {
                if(!canUse[j]) continue;
                ret[j] = ret[j] < ret[i] + 1 ? ret[j] : ret[i] +1;
                if(ret[j] > ret[n-1]) canUse[j] = false;
               
            }
        }
        if(maxReachIndex < n-1) return -1;
        return ret[n-1];
    }
};