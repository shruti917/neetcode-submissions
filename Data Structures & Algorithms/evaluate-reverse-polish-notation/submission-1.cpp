class Solution {
public:


int operation(int n1,int n2,char op){
if(op=='+') return n1+n2;
else if (op=='-') return n2-n1;
else if(op=='*') return n1*n2;
else  return n2/n1;
}
    int evalRPN(vector<string>& t) {
        int n=t.size();
        stack<int>st;

        for(int i=0;i<n;i++){
             if(t[i] != "+" && t[i] != "-" &&
               t[i] != "*" && t[i] != "/")  st.push(stoi(t[i]));
            
            else{
 
int num1= st.top();
st.pop();
                
        
int num2= st.top();
st.pop();


               int ans= operation(num1,num2,t[i][0]);
               st.push(ans);
            }
        }
        return st.empty()?0: st.top();
    }
};




 


