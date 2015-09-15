class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len < 1 || s[0] < '1' || s[0] > '9') return 0;
        vector<int> ret(len+1, 0);
        ret[0] = ret[1] = 1;
        for(int i=1; i < len; i++)
        {
            bool two = check(s, i-1, i), one = check(s, i, i);
            if(!two && !one) ret[i+1] = 0;
            if(two) ret[i+1] += ret[i-1];
            if(one) 
            {
                ret[i+1] += ret[i];
            }
            
            
        }
        return ret[len];
    }
private:
    bool check(const string s, int begin, int end)
    {
        if(end - begin > 1 || begin > end) return false;
        string tstr(s,begin, end-begin+1);
        if(end == begin)
        {
            if(tstr < "1" || tstr >"9") return false;
            else return true;
        }
        else
        {
            if(tstr >= "10" && tstr <= "26") return true;
            else 
                return false;
        }
    }
};