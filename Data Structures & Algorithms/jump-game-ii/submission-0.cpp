class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=1;i<n;i++){
nums[i]=max(nums[i], nums[i-1]-1);
        }
        int i=0;
        int count=0;

        while(i<n-1){
            i=nums[i]+i;
            count++;
        }
        return count;
    }
};
