class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        vector<int>vis(n+1,0);

        for(int i:nums){
            if(vis[i]==1) return i;
            vis[i]=1;
        }
        return 0;
    }
};
