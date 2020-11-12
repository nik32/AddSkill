#define SIZE 100000
​
class MyHashMap {
    
private:
    struct node{
        int key;
        int val;
        node* next;                
    };
    node *table[SIZE];
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for(int i = 0 ; i < SIZE ; i++)
            table[i] = NULL;
    }
    
    /*self made*/
    int hash(int key)
    {   return key % 100000; }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
                    
        node *head = table[hash(key)], *pri = NULL;
        while(head != NULL && head->key != key)
        {
            pri = head;
            head = head->next;
        }
        
        if(head != NULL)
            head->val = value;
