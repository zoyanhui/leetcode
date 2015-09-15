class Solution {
public:
     vector<vector<string> > solveNQueens(int n) 
     {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> queenPos(n, 0);
        vector<int> curPosInLines(n,0);
        int currentline = 0;
        ret.clear();
        if(n<=0) return ret;
        while(currentline >=0)
        {
            bool validQ = isValidQueen(queenPos, n, currentline);
            if(validQ)
            {
                if(currentline == n-1)
                {
                    //ret++; // record a solution
                    vector<string> solution;
                    for(int i=0; i<n; i++)
                    {
                        string s(n, '.');
                        s[queenPos[i]] = 'Q';
                        solution.push_back(s);
                    }
                    ret.push_back(solution);
                    
                    goNext(queenPos, currentline, n);
                }
                else
                {
                    queenPos[++currentline] = 0;
                }                
            }
            else
            {
                goNext(queenPos, currentline, n);
            }
        }
        return ret;
    }
private:
    vector<vector<string> > ret;
    void goNext(vector<int> &queenPos, int &currentline, const int n)
    {
        if(currentline < 0) return;
        if(queenPos[currentline] == n-1)   
        {
             currentline--;            // this line has been end, go back
             goNext(queenPos, currentline, n);
        }   
        else
            queenPos[currentline]++;
    }
    bool isValidQueen(vector<int> &queenPos, const int n, const int cur)
    {
        bool valid = true;
        for(int i=0; i<cur; i++)
        {
            if(queenPos[i] == queenPos[cur] || abs(queenPos[i]-queenPos[cur]) == abs(cur - i)) 
            {
                valid = false;
                break;
            }
        }
        return valid;
    }
};