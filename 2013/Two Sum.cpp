class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> record;
        int len = numbers.size();
        
        for(int i=0; i<len; i++)
        {
            int key = (target-numbers[i]) * numbers[i];
            if(record.find(key) != record.end())
            {
                int indicesL = record[key];
                if(numbers[indicesL] + numbers[i] == target)
                {
                    vector<int> ret;
                    ret.push_back(indicesL+1); ret.push_back(i+1);
                    return ret;
                }                
            }
            else
            {
                record.insert(pair<int,int>(key, i));
            }
        }
        vector<int> ret;
        return ret;
    }
};