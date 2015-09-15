class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        if(!s) return 0;
        const char *itr = s;
        int left = -1, retLen = 0;
        while(*itr != '\0')
        {
            if(*itr != ' ')
            {
                left = len;
                len ++;
                itr++;
                while(*itr != '\0' && *itr != ' ')
                {
                    len ++;
                    itr++;
                }
                retLen = len - left;
                continue;
            }
            len ++;
            itr++;
        }
        return retLen;        
    }
};