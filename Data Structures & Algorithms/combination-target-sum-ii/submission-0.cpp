
class Solution {
public:
    void combSum(vector<int>& cand, int target, int i,
                 int sum, vector<int>& subset,
                 vector<vector<int>>& res) {

        if (sum == target) {
            res.push_back(subset);
            return;
        }

        if (i >= cand.size() || sum > target) {
            return;
        }

        // Include the current element
        subset.push_back(cand[i]);

        combSum(cand, target, i + 1,
                sum + cand[i], subset, res);

        subset.pop_back();

        // Exclude the current element and skip duplicates
        int j = i + 1;
        while (j < cand.size() && cand[j] == cand[i]) {
            j++;
        }

        combSum(cand, target, j, sum, subset, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& cand,
                                         int target) {
        sort(cand.begin(), cand.end());

        vector<vector<int>> res;
        vector<int> subset;

        combSum(cand, target, 0, 0, subset, res);

        return res;
    }
};
