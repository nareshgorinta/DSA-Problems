#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value, freq;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

struct DLList {
    Node* head;
    Node* tail;
    int size;

    DLList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }

    Node* removeLast() {
        if (size == 0) return nullptr;
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache {
private:
    int capacity;
    int currSize;
    int minFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, DLList*> freqToList;

    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqToList[oldFreq]->removeNode(node);

        // If current list becomes empty, and this freq was minFreq
        if (oldFreq == minFreq && freqToList[oldFreq]->size == 0)
            minFreq++;

        node->freq++;
        int newFreq = node->freq;

        if (freqToList.find(newFreq) == freqToList.end())
            freqToList[newFreq] = new DLList();

        freqToList[newFreq]->addNode(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end())
            return -1;

        Node* node = keyToNode[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (currSize == capacity) {
            // Remove LFU node
            DLList* list = freqToList[minFreq];
            Node* nodeToRemove = list->removeLast();
            keyToNode.erase(nodeToRemove->key);
            currSize--;
        }

        Node* newNode = new Node(key, value);
        minFreq = 1;

        if (freqToList.find(minFreq) == freqToList.end())
            freqToList[minFreq] = new DLList();

        freqToList[minFreq]->addNode(newNode);
        keyToNode[key] = newNode;
        currSize++;
    }
};
