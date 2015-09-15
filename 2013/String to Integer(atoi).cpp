class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!str) return 0;
        long long ret = 0;
        bool mins = false;
        while(*str == ' ') str++;
        if(*str == '+') str++;
        if(*str == '-')
        {
            mins = true;
            str++;
        }
       
        while(*str != '\0')
        {
            if(*str <'0' || *str >'9')
            { 
                if(mins)
                    return 0-ret;
                else
                    return ret;
            
            }
            ret *= 10;
            ret += *str - '0';
            if(mins)
            {
                if(ret - INT_MAX >= 1) return INT_MIN;
            }
            
            else
                if(ret >= INT_MAX) return INT_MAX;
            str++;
        }
        if(mins)
            return 0-ret;
        else
            return ret;
    }
};