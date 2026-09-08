class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
          priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        
        for(auto c: points){
            int x=c[0];
            int y=c[1];

            int dist = x * x + y * y;
            pq.push({dist,c});

        }
vector<vector<int>>res;

        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
