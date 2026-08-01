class Solution {
public:

    vector<int>smallest_right(vector<int>& h){
int n= h.size();
vector<int>ans(n,n);
stack<int>st;
for(int i=n-1;i>=0;i--){
    while(!st.empty() && h[st.top()] >= h[i] ){
        st.pop();
    }
if(!st.empty())ans[i]=st.top();
st.push(i);
}
return ans;
    }

    vector<int>smallest_left(vector<int>& h){
int n= h.size();
vector<int>ans(n,-1);
stack<int>st;
for(int i=0;i<n;i++){
    while(!st.empty() && h[st.top()] >= h[i] ){
        st.pop();
    }
if(!st.empty())ans[i]=st.top();
st.push(i);
}
return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> l1= smallest_left(heights);
        vector<int> l2= smallest_right(heights);
        int n= heights.size();
        int ans=0;

        for(int i=0;i<n;i++){
int width = l2[i] - l1[i] - 1;
int area = heights[i] * width;
ans = max(ans, area);

        }
        return ans;

    }
};
