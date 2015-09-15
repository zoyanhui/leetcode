class Solution {
private:
    inline bool checkAlphanumeric(char c)
    {
        if(c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
            return false;
        else 
            return true;
    }
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len <= 0) return true;
        unsigned int left =0, right = len-1;
        while(left < right)
        {
            while(!checkAlphanumeric(s[left]) && left < right)
                left++;
            while(!checkAlphanumeric(s[right]) && left < right)
                right--;
            if(left >= right)
                break;
            if(s[left] != s[right])
            {
                if(s[left] >= 'A' && s[right] >= 'A') 
                {
                    if(s[left] - s[right] !=32 && s[left] - s[right] !=-32)
                        return false;
                }
                else
                    return false;
            }          
            
            left++; right--;    
        }
        return true;
    }
};