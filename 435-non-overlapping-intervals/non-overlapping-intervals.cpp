class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort by the end-time
        sort(intervals.begin(), intervals.end(),
        [](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        int count = 0;
        int lastEnd = INT_MIN;
        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1];
            if(start >= lastEnd){
                lastEnd = end;
            }
            else{
                count++;
            }
        }
        return count;
    }
};