class CQueue {
    stack<int> a,b;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        a.push(value);
    }
    
    int deleteHead() {
        if(b.empty()){
            if(!a.empty()){
                while(!a.empty()){
                    b.push(a.top());
                    a.pop();
                }
            }else{
                return -1;
            }
        }
        if(b.empty())return -1;
        else{
            int head=b.top();
            b.pop();
            return head;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */