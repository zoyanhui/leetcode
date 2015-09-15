class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == 0) return INT_MIN;
        
        int flag = true;
        long long  dend = dividend, dsor = divisor;;
        if(dend < 0)
        {            
            dend = 0 - dend;
            flag ^= true;
        }
        
        if(dsor < 0)
        {            
            dsor = 0 - dsor;
            flag ^= true;
        }
        
        if(dend < dsor)
            return 0;
        if(dend == dsor) return flag ? 1 : -1;
        
        long long dd = dend, dr = dsor;
        unsigned int lend = 0, lenr = 0;
        while(dd)
        {
            lend++;
            dd>>=1;
        }
        while(dr)
        {
            lenr++;
            dr>>=1;
        }
        dd = dend, dr = dsor;
        int deg = lend - lenr;
        dr <<= deg;
        long long ret = 0;
        while(deg)
        {
            if(dd >= dr)
            {
                long long temp = 1 <<deg;
                ret += temp;
                dd -= dr;
            }
            dr >>=1;
            deg--;
        }
        if(dd > dr)
        {
            ret++;
        }
        
        if(flag)
            return ret;
        else
            return 0-ret;
    }
};