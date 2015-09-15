class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strs.size();
        if(len== 0) return "";
        vector<int> indices(len, 0);
        string ret = "";
        int k = 0;
        while(1)
        {
            char com = strs[0][k];
            for(int i =0; i< len; i++)
            {
                if(strs[i][k] == '\0') return ret;
                if(strs[i][k] != com) return ret;
            }
            ret += com;
            k++;
        }
        return ret;
    }
};