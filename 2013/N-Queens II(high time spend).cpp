
class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //

	//instead initilization as memset
        if(n<=0) return 0;
        queenPos.clear();
        queenPos.resize(n, 0);
        canUse.clear();
        canUse.resize(n, true);

        //memset(canUse, true, sizeof(canUse));
        ret = 0;
        setQueens(0, n);
        
        return ret;
    }
private:
    int ret;
    vector<int> queenPos;   //set vector to normal int[], int queenPos[N]
    vector<bool> canUse;    //set vector to normal bool[],  bool canUse[N]
//    int queenPos[100];      bool canUse[100];
    void setQueens(int k, const int n)
    {
        if(k == n) 
        {
            ret++;
            return;
        }
                   
        for(int i=0; i<n; i++)
        {
            
            if(canUse[i] && canSetQ(k, i))
            {
                canUse[i] = false;
                queenPos[k] = i;
                setQueens(k+1, n);
                canUse[i] = true;
            }
        }
            
        
    }
   bool canSetQ(const int cur, const int index)
    {
        for(int i=0; i<cur; i++)
        {
            if(abs(queenPos[i]-index) == abs(cur - i)) 
            {
                return false;
            }
        }
        return true;
    }
};