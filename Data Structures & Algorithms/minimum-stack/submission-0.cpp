class MinStack {
public:
    stack<int> st;
    stack<int> mnst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (mnst.empty())
            mnst.push(val);
        else {
            int pre = mnst.top();
            mnst.push(min(pre, val));
        }
    }
    
    void pop() {
        st.pop();
        mnst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnst.top();
    }
};
