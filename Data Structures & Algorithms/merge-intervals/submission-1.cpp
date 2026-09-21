class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int i=1;
     sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        res.push_back(intervals[0]);
   
        while(i<n){
int last= res.back()[1];
if(last>= intervals[i][0]){
while(i<n && last>= intervals[i][0]){
    last= max(last,intervals[i][1]);
    i++;
}
res.back()[1]=last;
}
else{
    res.push_back(intervals[i]);
    i++;
}


        }
        return res;

    }
};
