//my first answer:
//firstly sort S,and then from begin to end, using map record who was duplicate and how many dulication.

class Solution {
private:
    vector<vector<int> > ret;
    map<int, int> mark;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        mark.clear();
        int len = 0;
        for(vector<int>::iterator myiter = S.begin(); myiter != S.end(); ++myiter, len++)
        {
           
            mark.insert(pair<int,int>(*myiter,0));
        }
        ret.push_back(vector<int>());
        
        sort(S.begin(),S.end());
        
        for(int i=0; i <len; i++)
        {
            if(mark[S[i]] == 0)
            {
                int tlen = ret.size();
                for(int j=1; j<tlen; j++)
                {
                    vector<int> temp = ret[j];
                    temp.push_back(S[i]);
                    ret.push_back(temp);
                }
                ret.push_back(vector<int>(1,S[i]));
                mark[S[i]]++;
            }
            else
            {
                int tlen = ret.size() , count = mark[S[i]];
                for(int j=1; j<tlen; j++)
                {
                    vector<int> temp = ret[j];
                    if(findC(temp,S[i]) == count)
                    {
                        temp.push_back(S[i]);
                        ret.push_back(temp);
                    }    
                }
                mark[S[i]]++;
            }
        }
        
        return ret;
    }
    unsigned int findC(vector<int> &v, int value)
    {
        int count = 0;
        for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            if(*it == value)
                count ++;
        }
        return count;
    }
};