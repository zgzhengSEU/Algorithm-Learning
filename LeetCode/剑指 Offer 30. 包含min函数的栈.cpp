class MinStack {
    stack<int> s;
    stack<int> smin;
    int min1,min2=INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if(smin.empty()||x<=smin.top())smin.push(x);
    }
    
    void pop() {
        if(s.top()==smin.top())smin.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */