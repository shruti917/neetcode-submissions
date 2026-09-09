class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp;

        for (char c : tasks)
            mp[c]++;

        int maxFreq = 0;

        for (auto it : mp) {
            maxFreq = max(maxFreq, it.second);
        }

        int countMax = 0;

        for (auto it : mp) {
            if (it.second == maxFreq)
                countMax++;
        }

        int result = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), result);
    }
};