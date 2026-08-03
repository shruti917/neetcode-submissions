class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1;
        int leftMax= h[l],rightMax= h[r];
int ans=0;
        while(l<r){
            if(h[l]< h[r]){
                l++;
                leftMax= max(leftMax, h[l]);
                ans+= (leftMax- h[l]);
            }
            else{
                r--;
                rightMax= max(rightMax, h[r]);
                ans+= (rightMax- h[r]);
            }
        }
        return ans;
    }
};
