class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 1;
        if(x==0) return 0;
        if(x==1) return 1;
	    if(x==-1) return n % 2 ? -1 : 1;
        if(n < 0) return 1.0/pow(x,-n);
        double base = x, ans = 1;
	    while(n)
	    {   
            if(n & 0x1)
                ans *= base;
            base *= base;
            n >>=1;
        }
        return ans;
    }
};