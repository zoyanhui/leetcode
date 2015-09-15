class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len <= 1) return 0;
        vector<int> sBracket;
        for(int i=0; i< len; i++)
        {
            if(s[i] == lBracket)
            {
                sBracket.push_back(lBracket);
                
            }
            
            else if(s[i] == rBracket)
            {
                if(sBracket.size() == 0)
                {
                    continue;
                }
                else
                {
                    int j;
                    for(j=sBracket.size()-1; j>=0; j--)
                    {
                        if(sBracket[j] == rBracket)
                        {
                            sBracket.push_back(rBracket);
                            break;
                        }
                        if(sBracket[j] == lBracket)
                        {
                            sBracket[j] = 2;
                            break;
                        }
                            
                    }
                    if(j < 0)
                        sBracket.push_back(rBracket);
                }
                    
            }
        }
        int ret = 0, cur = 0;
        for(int i =0; i< sBracket.size(); i++)
        {
            if(sBracket[i] == lBracket || sBracket[i] == rBracket)
            {
                if(cur > ret) ret = cur;
                cur = 0;
            }
            else
                cur += sBracket[i];
        }
        if(cur > ret) ret = cur;   
        return ret;
    }
private:
    const char lBracket = '(';
    const char rBracket = ')';
};