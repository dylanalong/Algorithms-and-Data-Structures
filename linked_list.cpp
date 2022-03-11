#include<iostream>

struct Node {
    int value;
    Node* next_node;
};


class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList();
        ~LinkedList();
        void push(int value);
        int pop();
        void insert(int value, int index);
        void remove(int index);
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next_node;
        delete temp;
    }
}

void LinkedList::push(int value) {
    Node* new_node = new Node;
    new_node->value = value;
    new_node->next_node = nullptr;

    if (head == nullptr) {
        head = new_node;
    }
    else if (tail == nullptr) {
        tail = new_node;
        head->next_node = tail;
    }
    else {
        tail->next_node = new_node;
        tail = new_node;
    }
}

int LinkedList::pop() { //acting as a queue
    Node* popped_node = head;
    head = head->next_node;

    int popped_value = popped_node->value;  
    delete popped_node;

    return popped_value;
}

void LinkedList::insert(int value, int index) {
    
}

int main(int argc, char** argv) {
    LinkedList l;
    l.push(5);
    l.push(10);
    l.push(15);
    return 0;
}