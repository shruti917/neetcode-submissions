class Solution {
public:
    int carFleet(int t, vector<int>& pos, vector<int>& s) {
 
 vector<pair<int,int>>st;
 int n= pos.size();

 for(int i=0;i<n;i++){
st.push_back({pos[i],s[i]});
 }
 sort(st.rbegin(),st.rend());
 int ans=1;

 double prvT= (double) (t- st[0].first)/st[0].second;

 for(int i=1;i<n;i++){
double currT=  (double) (t- st[i].first)/st[i].second;

if(prvT < currT){
    ans++;
     prvT= currT;
}
 }

 return ans;
    }
};
