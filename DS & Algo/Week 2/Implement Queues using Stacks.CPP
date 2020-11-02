class MyQueue {
private:
    stack<int> que, temp_que;
public:
    
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {  que.push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        int top = 0;
        while(que.size() > 1)
        {
            temp_que.push(que.top());
            que.pop();
        }
        top = que.top();
        que.pop();

        while(!temp_que.empty())
        {
            que.push(temp_que.top());
            temp_que.pop();
        }   
        return top; 
    }
    
    /** Get the front element. */
    int peek() 
    {   
        int top = 0;
        while(!que.empty())
        {
            top = que.top();
            temp_que.push(top);
            que.pop();
        }
        while(!temp_que.empty())
        {
            que.push(temp_que.top());
            temp_que.pop();
        }   
        return top;   
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {   return que.size() ? 0 : 1;  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
