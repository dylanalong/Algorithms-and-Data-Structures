template <class X>
class Node {
    private:
        typedef X value_type;
    public:
        Node(value_type data) {
            this->data = data;
            this->next = nullptr;
        }
        value_type data;
        Node<value_type>* next;
};


template <class T>
class Stack {
private:
    typedef T value_type;
    Node<value_type>* top;
public:
    Stack();
    ~Stack();
    void push(value_type data);
    value_type pop();
    value_type peek();
    bool is_empty();
};

template <class value_type>
Stack<value_type>::Stack() {
    top = nullptr;
}

template <class value_type>
Stack<value_type>::~Stack()
{
    while (top != nullptr) {
        Node<value_type>* temp = top;
        top = top->next;
        delete temp;
    }
}

template <class value_type>
void Stack<value_type>::push(value_type data) {
    Node<value_type>* new_node = new Node<value_type>(data);

    if (top == nullptr) {
        top = new_node;
    }
    else {
        new_node->next = top;
        top = new_node;
    }
}

template <class value_type>
value_type Stack<value_type>::pop() {
    Node<value_type>* popped_node = top;
    value_type data = top->data;
    top = top->next;
    delete popped_node;
    return data;
}

template <class value_type>
value_type Stack<value_type>::peek() {
    return top->data;
}

template <class value_type>
bool Stack<value_type>::is_empty() {
    return top == nullptr;
}

int main(int argc, char** argv) {
    Stack<int> stack;

    for (int i = 0; i < 5; i++) {
        stack.push(i+1);
    }
    int popped = stack.pop();
    popped = stack.pop();
    popped = stack.pop();
    popped = stack.pop();
    popped = stack.pop();
    bool empty = stack.is_empty();
    return 0;
}