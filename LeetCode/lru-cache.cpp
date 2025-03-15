class LRUCache {
    public:
        struct node{
            node *next;
            node *prev;
            int key, val;
            node(int k, int v){
                key = k;
                val = v;
                next = nullptr;
                prev = nullptr;
            }
        };
    
        int cap = 0;
        node *head, *tail;
        map<int, node*> mp;
        LRUCache(int capacity) {
            cap = capacity;
            head = new node(-1, -1);
            tail = new node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
        
        int get(int key) {
            if(mp.find(key) == mp.end()) return -1;
            int v = mp[key]->val;
            update(mp[key]);
            return v;
        }
        
        void put(int key, int value) {
            if(mp.find(key) != mp.end()){
                node *t = mp[key];
                t->prev->next = t->next;
                t->next->prev = t->prev;
                mp.erase(key);
            }
            if(mp.size() == cap){
                node *t = head->next;
                mp.erase(t->key);
                head->next = t->next;
                t->next->prev = head;
            }
            node *t = new node(key, value);
            mp[key] = t;
            head->next->prev = t;
            t->next = head->next;
            head->next = t;
            t->prev = head;
            update(t);
        }
    
        void update(node *t){
            t->next->prev = t->prev;
            t->prev->next = t->next;
            t->prev = tail->prev;
            t->next = tail;
            tail->prev->next = t;
            tail->prev = t;
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */