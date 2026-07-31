class MinStack {
public:
stack<int>st;
multiset<int>pq;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        pq.insert(val);
    }
    
    void pop() {
        
        pq.erase(pq.find(st.top()));
        st.pop();
    }
    
    int top() {
       return st.top();
     
    }
    
    int getMin() {

      
        return *pq.begin();

    }
};
