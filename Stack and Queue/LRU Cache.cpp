class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node* next;
        Node *prev;
        Node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };

    void deleteNode(Node* node){
        Node* prevNode= node->prev;
        Node* afterNode= node->next;
        prevNode->next= afterNode;
        afterNode->prev= prevNode;
        
    }

    void insertAfterHead(Node* node){
        Node* comeAfterHead = head->next;
        head->next= node;
        node->next= comeAfterHead;
        node->prev= head;
        comeAfterHead->prev = node;
    }

    int cap;
    unordered_map<int, Node*> mpp;
    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    LRUCache(int capacity) {
        cap= capacity;
        tail->prev = head;
        head->next = tail;
    }

    int get(int key){
        if(!mpp.contains(key)) return -1;
        Node* node= mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.contains(key)){
            Node* node=mpp[key];
            node->val= value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else {
            if(mpp.size()==cap){
                Node* node= tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node= new Node(key, value);
            mpp[key]= node;
            insertAfterHead(node);
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */