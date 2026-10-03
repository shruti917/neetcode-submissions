class Solution {
public:

    void perm( vector<int>nums,vector<vector<int>>&res,vector<bool>&used,vector<int>&curr){
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i])continue;
            used[i]=true;
            curr.push_back(nums[i]);
             perm(nums,res,used,curr);
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        vector<bool>used(n,false);
        vector<int>curr;
        perm(nums,res,used,curr);
        return res;
    }
};
