class MyStack {
private:
    queue<int> stk, temp_stk;
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) 
    {  stk.push(x); }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() 
    {
        int top = 0;
        while(stk.size() > 1)
        {
            temp_stk.push(stk.front());
            stk.pop();
        }
        top = stk.front();
        stk.pop();

        while(!temp_stk.empty())
        {
            stk.push(temp_stk.front());
            temp_stk.pop();
        }   
        return top; 
    }
    
    /** Get the top element. */
    int top() 
    {   
        int top = 0;
        while(!stk.empty())
        {
            top = stk.front();
            temp_stk.push(top);
            stk.pop();
        }
        while(!temp_stk.empty())
        {
            stk.push(temp_stk.front());
            temp_stk.pop();
        }   
        return top;   
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {   return stk.size() ? 0 : 1;  }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
