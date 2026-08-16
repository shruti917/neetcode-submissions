class Solution {
public:
int consumed(vector<int>& piles, int h){
    int n=piles.size();
    int sum=0;
for(int i=0;i<n;i++){
    sum+=(piles[i]/h);
    if(piles[i]%h !=0) sum++;
}
return sum;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=-1;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        if(n==h)return maxi;

        int s=1;
        int e=maxi;
        int ans=maxi;

        while(s<=e){
            int mid= s+(e-s)/2;
            int c= consumed(piles,mid);
            if(c<=h){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
