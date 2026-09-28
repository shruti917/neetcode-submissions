class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& q) {
                int n = q.size();
        int m = intervals.size();

        vector<int> res(n, -1);
        
        sort(intervals.begin(),intervals.end());
        
        vector<pair<int,int>>queries;
        for(int i=0;i<q.size();i++)queries.push_back({q[i],i});

        sort(queries.begin(),queries.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        int i = 0;

        for (auto& query : queries) {

            int x = query.first;
            int idx = query.second;

            // Add all intervals whose left <= current query
            while (i < m && intervals[i][0] <= x) {

                int left = intervals[i][0];
                int right = intervals[i][1];

                int len = right - left + 1;

                pq.push({len, right});

                i++;
            }

            // Remove intervals that cannot contain current query
            while (!pq.empty() && pq.top().second < x) {
                pq.pop();
            }

            // Top contains the shortest valid interval
            if (!pq.empty()) {
                res[idx] = pq.top().first;
            }
        }

        return res;

    }
};

