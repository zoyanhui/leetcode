/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = intervals.size();
        if(size == 0) return vector<Interval>(1, newInterval);
        int indexS = -1, indexE = -1;
        vector<Interval> ret;
        for(int i=0; i< size; i++)
        {
            if(intervals[i].start > newInterval.start) 
            {
                indexS = i;
                break;
            }
            ret.push_back(intervals[i]);
        }
        
        if(indexS < 0)
        {
           if(intervals[size-1].end >= newInterval.start) ret[size-1].end = newInterval.end > intervals[size-1].end ? newInterval.end : intervals[size-1].end;
           else
              ret.push_back(newInterval);           
        }
        else
        {
            int k = indexS;            
            int end = newInterval.end;
            while(k < size && newInterval.end >= intervals[k].start)
            {
                end = end > intervals[k].end ? end : intervals[k].end;
                k++;
            }
            if(indexS!=0 && intervals[indexS-1].end >= newInterval.start)
            {
                ret[indexS-1].end = end > intervals[indexS-1].end ? end : intervals[indexS-1].end;
            }
            else
            {
                Interval nInterval(newInterval.start, end);
                ret.push_back(nInterval);
            }  
            for(int i=k; i <size; i++)
                ret.push_back(intervals[i]);
                
        }
        
        return ret;
    }
};