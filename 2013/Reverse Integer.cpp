class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x == 0) return x;
        bool isPos = true;
        if(x<0) { isPos = false; x = -x;}
        int ans = 0;
        while(x)
        {
            ans *= 10;
            ans += x%10;
            x /= 10;
        }
        
        
        if(isPos)
            return ans;
        else 
            return -ans;
    }
};