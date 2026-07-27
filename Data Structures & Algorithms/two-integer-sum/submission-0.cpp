class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
    
        for(int i=0;i<n;i++){
            int diff= target- nums[i];
            if(mp[diff]>=1){
                return {mp[diff]-1,i};
            }
            mp[nums[i]]=i+1;
        }
        return {-1,-1};
    }
};
