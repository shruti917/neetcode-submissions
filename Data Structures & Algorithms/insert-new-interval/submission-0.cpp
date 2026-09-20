class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInt) {
        vector<vector<int>>res;
        int n=inter.size();
        int i=0;

        if (n == 0) {
            res.push_back(newInt);
            return res;
        }

           while (i < n && inter[i][1] < newInt[0]) {
            res.push_back(inter[i]);
            i++;
        }

             while (i < n && inter[i][0] <= newInt[1]) {
            newInt[0] = min(newInt[0], inter[i][0]);
            newInt[1] = max(newInt[1], inter[i][1]);
            i++;
        }

        // Add new/merged interval
        res.push_back(newInt);

  while (i < n) {
            res.push_back(inter[i]);
            i++;
        }


return res;
    }
};
