class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      
        vector<int>&l= nums1;
        vector<int> &h= nums2;
        int total= l.size()+h.size();
        int half= (total+1)/2;

        if(h.size() < l.size()) swap(l,h);

        int n=0;
        int m=l.size();

        while(n<=m){
            int i=(n+m)/2;
            int j= half-i;

            int Aleft= i>0? l[i-1]:INT_MIN;
            int Aright= i<l.size()? l[i] :INT_MAX;
             int Bleft= j>0? h[j-1]:INT_MIN;
            int Bright= j<h.size()? h[j] :INT_MAX;




            if(Aleft <= Bright && Bleft <=Aright ){
                if(total%2!=0){
                    return max(Aleft,Bleft);
                }
                return (max(Aleft,Bleft)+ min(Aright,Bright))/2.0;
            }
            else if(Aleft>Bright) m= i-1;
            else n= i+1;
        }

        return -1;

    }
};
