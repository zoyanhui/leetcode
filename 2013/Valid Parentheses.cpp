class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        stack<char> sStr;
        while(s[i] !='\0')
        {
            switch(s[i])
            {   
                case '(':                   
                case '[':                    
                case '{':
                    sStr.push(s[i]);
                    break;
                case ')':  
                    if(sStr.empty() || sStr.top() != '(') return false;
                    else sStr.pop();
                    break;
                case ']':
                    if(sStr.empty() || sStr.top() != '[') return false;
                    else sStr.pop();
                    break;
                case '}':
                    if(sStr.empty() || sStr.top() != '{') return false;
                    else sStr.pop();
                    break;
                default :
                    return false;
            }
            i++;
        }    
       return sStr.empty();
    }
};