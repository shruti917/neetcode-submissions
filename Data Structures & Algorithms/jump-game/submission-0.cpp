class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        for(int i=1;i<nums.size();i++){
            nums[i]= max(nums[i],nums[i-1]-1);
        }
int i=0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] <= 0)
                return false;
        }
       return true;
    }
};
