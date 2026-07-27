class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto it :mp){
            pq.push({it.second,it.first});
        }

        vector<int> res;

        while(k--){
            if(!pq.empty()){
                res.push_back(pq.top().second);
                pq.pop();
            }

        }
        return res;
    }
};
