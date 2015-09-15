/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool intervalCmp(const Interval &left, const Interval &right)
{
    if(left.start < right.start) return true;
    else return false;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), intervalCmp);
        vector<Interval> ret;
        for(int i=0; i<intervals.size(); i++)
        {
            if(ret.size() == 0)
            {
                ret.push_back(intervals[i]);
            }
            else
            {
                int k = ret.size();
                if(ret[k-1].end >= intervals[i].start)
                {
                    ret[k-1].end = ret[k-1].end > intervals[i].end ? ret[k-1].end :intervals[i].end;
                }
                else
                    ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};