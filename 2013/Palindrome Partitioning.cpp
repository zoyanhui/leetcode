class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vec.clear();
                vector<string> v;
                partition(s,0,v);
                return vec;
    }
    private:
            vector<vector<string>> vec;
            void partition(string s, int start,vector<string> &v)
            {
                if(start == s.length())
                {                   
                   vector<string> temp(v);
                   vec.push_back(temp);
                   return;
                }
                for(int i=start; i < s.length(); i++)
                {
                    if(isPalindrome(s,start,i))
                    {
                       v.push_back(s.substr(start,i-start+1));
                       partition(s,i+1,v);
                       v.pop_back();
                    }
                }
                return;
            }
            bool isPalindrome(string s,int start, int end)
            {
                while(start < end)
                {
                    if(s[start] != s[end])
                       return false;
                    start++;
                    end--;
                }
                return true;
            }
};