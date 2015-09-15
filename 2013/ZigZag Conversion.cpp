class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(nRows == 1) return s;
        vector<string> converted(nRows, "");
        int k = 0, i= 0;
        bool down = true;
        while(s[i] != '\0')
        {
            converted[k] += s[i];
            i++;
            if(k == nRows - 1) 
            {
                down = false;
            }
            if(k == 0)
                down = true;
            if(down)
                k++;
            else
                k--;
            
        }
        string ret="";
        for(int i =0; i< nRows; i++)
            ret += converted[i];
        return ret;
    }
};