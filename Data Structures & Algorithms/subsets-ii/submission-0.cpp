class Solution {
public:
    void subsetDup(vector<int> nums,int i,vector<vector<int>>&res,vector<int>&curr){
        if(i==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        subsetDup(nums,i+1,res,curr);

        curr.pop_back();
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) {
            j++;
        }
        subsetDup(nums,j,res,curr);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>res;
         vector<int>curr;
           sort(nums.begin(), nums.end());
         subsetDup(nums,0,res,curr);
         return res;
    }
};
