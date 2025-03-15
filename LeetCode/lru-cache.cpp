class LRUCache {
    public:
        int cap = 0, size = 0;
        class node{
            public : 
            int key, val;
            node *next, *prev;
            node(int x, int y){
                key = x, val = y;
                next = prev = nullptr;
            }
        };
    
        node *head = new node(-1, -1);
        node* tail = new node(-1, -1);
    
        void add(node *n){
            node *t = head->next;
            t->prev = n;
            head->next = n;
            n->next = t;
        }
    
        void deletenode(node *n){
            node *nx = n->next, *pv = n->prev;
            nx->prev = pv;
            pv->next = nx;
        }
    
        LRUCache(int capacity) {
            cap = capacity;
            head->next = tail;
            tail->prev = head;
        }
        
        int get(int key) {
            node *t = head;
            while(t != nullptr && t->key != key) t = t->next;
            if(t == nullptr) return -1;
            return t->val;
            deletenode(t);
            add(t);
        }
        
        void put(int key, int value) {
            node *t = head;
            while(t != nullptr && t->key != key) t = t->next;
            if(t == nullptr){
                t = new node(key, value);
                add(t);
                size++;
                if(size > cap){ size--; deletenode(tail->prev); }
            }
            else { deletenode(t); add(t); }
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */