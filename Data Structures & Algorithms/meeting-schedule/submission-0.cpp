class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

        int n = intervals.size();

        if (n == 0) return true;

        int end = intervals[0].end;

        for (int i = 1; i < n; i++) {

            // Current meeting starts before previous meeting ends
            if (intervals[i].start < end) {
                return false;
            }

            end = max(end, intervals[i].end);
        }

        return true;
    }
};