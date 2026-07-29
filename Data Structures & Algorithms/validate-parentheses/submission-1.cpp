class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='['|| s[i]=='('|| s[i]=='{') st.push(s[i]);
            else if(s[i]=='}'|| s[i]==']'|| s[i]==')'){
                 if (st.empty()) return false; 
                int top= st.top();
                st.pop();
                if((s[i]=='}' && top=='{')|| (s[i]==']' && top=='[')|| (s[i]==')' && top=='(')) continue;
                else return false;
            }
        }
        return st.empty()? true:false;
    }
    
};
