#include <unordered_map>
using namespace std;

class LRUCache {
public:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // helper: add node just before tail (most recent position)
    void addNode(Node* node) {
        Node* prevTail = tail->prev;
        prevTail->next = node;
        node->prev = prevTail;
        node->next = tail;
        tail->prev = node;
    }

    // helper: remove node from list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        // move this node to the end (most recently used)
        removeNode(node);
        addNode(node);

        return node->value;
    }
    
    void put(int key, int value) {
        // if key exists → update and move to end
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addNode(node);
        } 
        else {
            // if cache full → remove least recently used (head->next)
            if (cache.size() == capacity) {
                Node* lru = head->next;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }

            // insert new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
        }
    }
};
