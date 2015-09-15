class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        if(!s) return 0;
        const char *itr = s;
        while(*itr != '\0')
        {
            len ++;
            itr++;
        }
        if(len ==0) return 0;
        
        while(len >0 && *(s+len-1) == ' ') len--;
        if(len == 0) return 0;
        int left = len-1;
        while(left >= 0 && *(s+left) != ' ') left--;
        return len - left - 1;
        
    }
};