class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
        int len = numbers.size();
        
        assert(len >= 2);
            
        map<int, int> record;   // in c++ STL, map has initial values zero
        for(int i=0; i<len; i++)
        {
            int key = (target-numbers[i]) * numbers[i];
            //if(record.find(key) != record.end())       //map don't need to find key
            if(record[key] > 0)                          //has not inserted key, is map to zero
            {
                int indicesL = record[key];
                if(numbers[indicesL-1] + numbers[i] == target)
                {
                    vector<int> ret;
                    ret.push_back(indicesL); ret.push_back(i+1);
                    return ret;
                }                
            }
            else
            {
                //record.insert(pair<int,int>(key, i));     // insert is not necessary
                record[key] = i+1;                          // setting value directly is OK
            }
        }
        vector<int> ret;
        return ret;
    }
};