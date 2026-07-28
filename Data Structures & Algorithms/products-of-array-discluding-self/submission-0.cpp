class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        int zero=0;
        int pro=1;

        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            else pro*= nums[i];
        }

        for(int i=0;i<n;i++){
            if(zero >=2) return res;
            else if(zero==1){
                if(nums[i]==0) res[i]=pro;
            }
            else{
                res[i]= pro/nums[i];
            }
        }

        return res;

    }
};
