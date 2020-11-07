​
class MinStack {
private :
    int stack[100000], size, min_stack[100000];//min_stack[i] will store the minimum element when there are i elements in the main stack.
public:
    int min(int n1, int n2)
    {    return n1 < n2 ? n1 : n2;   }
    
    /** initialize your data structure here. */
    MinStack() {
        size = -1;
        size = -1;
    }
    
    void push(int x) {
        size++;
        stack[size] = x;
        min_stack[size] = !size ? x : min(min_stack[size-1], x);//now if x is first element in stack (i.e. size = 0) then x will be the min element. Otherwise we know min_stack[i-1] is the minimum for i-1 elemtns. So if we have x as ith elemnt then whichever is min out of min_stack[i-1] & x will be the minimum for min_stack[i].
    }
    
    void pop() {
        size--;//now becuase we pop we just reduce the size. Now becuase size for main stack decreased the size for min_stack will also decrese 
    }
    
    int top() {
        return stack[size];
    }
    
    int getMin() {
        return min_stack[size];
    }
};
​
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
