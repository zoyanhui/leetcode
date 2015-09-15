class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret = letterCombinations(digits , 0);
        return ret;        
    }
private:
    vector<string> letterCombinations(string digits ,int index)
    {
        vector<string> ret;
        if(digits[index] == '\0') return vector<string>(1, "");
        vector<char> vc = getChar(digits[index]);
        if(vc.empty()) return ret;   // wrong inputs
        for(int i=0; i < vc.size(); i++)
        {
            string s(1, vc[i]);
            vector<string> v = letterCombinations(digits ,index+1);
            if(v.empty())
                ret.push_back(s);
            for(int j=0; j < v.size(); j++)
            {
                ret.push_back(s + v[j]);
            }
        }
        return ret;        
        
    }
    vector<char> getChar(char num)   //k = 0, 1, 2, presents three characters of every num
    {
        vector<char> vc;
        if(num <'2' || num > '9') return vc;
        if(num < '7')
        {
            for(int k=0; k < 3; k++)
            {
                vc.push_back((num-'2') * 3 + 'a' + k);
            }
        }            
        else
        {
            if(num == '7')  // '7' has 4 nums
            {
                for(int k=0; k < 4; k++)
                {
                    vc.push_back('p' + k);
                }
            }
            else if(num == '8')
            {
                for(int k=0; k < 3; k++)
                {
                    vc.push_back('t' + k);
                }
            }
            else
            {
                for(int k=0; k < 4; k++)
                {
                    vc.push_back('w' + k);
                }
            }
        }
        return vc;
    }
};