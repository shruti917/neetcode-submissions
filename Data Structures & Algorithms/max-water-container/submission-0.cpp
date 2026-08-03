class Solution {
public:
    int maxArea(vector<int>& h) {
        int i=0,j=h.size()-1;
        int maxi=0;
        int ans=0;

            while(i<j){
                if(h[i]<h[j]){
                    maxi= (j-i)* h[i];
                    i++;
                }
                else{
                    maxi= (j-i)* h[j];
                    j--;
                }
                ans=max(ans,maxi);
            }
            return ans;
    }
};
