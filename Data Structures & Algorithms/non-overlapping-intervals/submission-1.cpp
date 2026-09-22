class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](vector<int>&a,vector<int>&b) {return a[1] <b[1];});

        int ans=0;
        int n=intervals.size();
        int last=intervals[0][1];
        for(int i=1;i<n;i++){

if(last>intervals[i][0])ans++;
else last= intervals[i][1];
        }
        return ans;
    }
};


