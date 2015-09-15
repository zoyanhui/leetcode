class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1) return "1";
        string s = countAndSay(n-1);
        string ret = "";
        
        int len = s.length();
        if(len == 0) return ret;
        char c = s[0];
        int num = 1;
        for(int i=1; i<len; i++)
        {
            if(i < len && s[i] == c)
            {
                num++;
            }
            else if(i < len && s[i] != c)
            {
                ret += string(1,num+'0');
                ret += string(1,c);
                num = 1;
                c = s[i];
            }
        }
        ret += string(1,num+'0');
        ret += string(1,c);
        return ret;
    }
};