/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {


                sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

       priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        int n=intervals.size();
        if(n==0|| n==1)return n;

        while(i<n){
            if(!pq.empty() && pq.top()<= intervals[i].start )pq.pop();
            pq.push(intervals[i].end);
            i++;
        }
return pq.size();
 
    }
};
