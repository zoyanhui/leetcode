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
        for(int i=0; i< size; i++)
        {
            if(intervals[i].start > newInterval.start && indexS < 0) indexS = i;
            if(intervals[i].start > newInterval.end && indexE < 0) indexE = i;
        }
        if(indexS < 0)
        {
           if(intervals[size-1].end >= newInterval.start) intervals[size-1].end = newInterval.end > intervals[size-1].end ? newInterval.end : intervals[size-1].end;
           else
              intervals.push_back(newInterval);           
        }
        else
        {
            int k = indexS;
            
            if(indexE < 0) indexE = size;
            
            int end = newInterval.end;
            int c = k;
            while(c < indexE)
            {
                end = end > intervals[k].end ? end : intervals[k].end;
                intervals.erase(intervals.begin()+k);
                c++;
            }
            if(k!=0 && intervals[k-1].end >= newInterval.start)
            {
                intervals[k-1].end = end > intervals[k-1].end ? end : intervals[k-1].end;
            }
            else
            {
                intervals.insert(intervals.begin()+k, newInterval);
                intervals[k].end = end;
            }
            
           
                
                
        }
        
        return intervals;
    }
};