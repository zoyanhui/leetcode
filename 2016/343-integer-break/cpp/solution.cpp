
#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n<2){
            return 1;
        }
        int *maxValues = new int[n+1];        
        for(int i=0;i<=n;i++){
            maxValues[i] = 0;
        }
        maxBrokenProduct(n, maxValues, false);
        int ret = maxValues[n];
        delete maxValues;
        maxValues = 0;
        return ret;
    }

    void maxBrokenProduct(int n, int *maxValues, bool bre){
        if(maxValues[n] != 0){
            return;
        }
        if(bre)
            maxValues[n] = n;
        for(int i=1; i<n; i++){
            maxBrokenProduct(n-i, maxValues, true);
            int cur = maxValues[n-i] * i;
            if(cur > maxValues[n]){
                maxValues[n] = cur;
            }
        }
    }

    // Below two functions are recursive method, which will be slow
    int integerBreakByRecursive(int n) {
        if(n<2){
            return 1;
        }
        return integerBreakByRecursive(n, false);
    }

    int integerBreakByRecursive(int n, bool bk){    
        int max = bk ? n : 0;  
        for(int i=1; i<n; i++){
            int cur = integerBreakByRecursive(n-i, true) * i;
            if(cur > max){
                max = cur;
            }
        }
        return max;
    }
};


int main(){
    int N;    
    cin>>N;
    Solution solution;
    while(N > 0){        
        cout<<solution.integerBreak(N)<<endl;    
        cin>>N;
    }
}