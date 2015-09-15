//DP, record history
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> ans(n+1,0);
        ans[0] = 0; ans[1] = 1; ans[2] = 2;
        for(int i=3; i<=n; i++)
        {
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }
};


// two variable
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int one = 1, two = 2;
        for(int i=3; i<=n; i++)
        {
           int temp = two;
           two += one;
           one = temp;
        }
        return two;
    }
};