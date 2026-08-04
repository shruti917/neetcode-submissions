class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int maxi=p[0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(p[i]< maxi){
                maxi=p[i];

            }
            else{
                ans= max(ans,p[i]-maxi);
            }
        }
        return ans;
    }
};
