class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len<=1) return s;
        int maxlen = -1;
        string ret = "";
        for(int i=0; i < len-1; i++)
        {
            if(len - 1 - i + 1 < maxlen) return ret;
            for(int j = len-1; j > i; j--)
            {
                if(j - i + 1 < maxlen) break;
                if(s[i] != s[j]) continue;
                int e = j, h = i;
                while(s[h] == s[e] && e > h)
                { 
                    e--;
                    h++;
                }
                if(e <= h) 
                {
                    int tlen = j - i +1;
                    if(tlen > maxlen)
                    {
                        maxlen = tlen;
                        ret = s.substr(i, tlen);
                        break;
                    }
                }
            }
            
            
        }
        return ret;
    }
};