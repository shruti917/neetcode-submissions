class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n= temp.size();
        vector<int> res(n,0);
        stack<pair<int,int>>st;

     for(int i=0;i<n;i++){
        int t= temp[i];
        while(!st.empty() && t> st.top().first){
            auto pair= st.top();
            st.pop();
            res[pair.second]= i- pair.second;
        }
        st.push({t,i});
     }   
     return res;
    }
};
