class Solution {
public:

    void combSum(vector<int>& nums,
                 int target,
                 vector<int>& subset,
                 int i,
                 vector<vector<int>>& res,
                 int sum) {

        // Found a valid combination
        if (sum == target) {
            res.push_back(subset);
            return;
        }
      

        // No more numbers
        if (i >= nums.size() || sum > target) {
            return;
        }

        // Include nums[i]
        subset.push_back(nums[i]);

        // IMPORTANT: i, not i+1
        // because we can reuse nums[i]
        combSum(nums, target, subset,
                i, res, sum + nums[i]);

        // Backtrack
        subset.pop_back();

        // Exclude nums[i]
        // Move to the next number
        combSum(nums, target, subset,
                i + 1, res, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;

        combSum(nums, target, subset, 0, res, 0);

        return res;
    }
};