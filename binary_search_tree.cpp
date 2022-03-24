#include<iostream>

template <class T>
class Node {
    public:
        Node(T data) {
            this->data = data;
            left_child = nullptr;
            right_child = nullptr;
        }
        ~Node() {
            delete left_child;
            delete right_child;
        }
        T data;
        Node* left_child;
        Node* right_child;
};

template <typename T>
void insert(Node<T>* &root, T data) {
    if (root == nullptr) {
        Node<T>* new_node = new Node<T>(data);
        root = new_node;
    }
    else {
        if (data <= root->data) {
            insert(root->left_child, data);
        }
        else {
            insert(root->right_child, data);
        }
    }
}

template <typename T>
Node<T>* find(Node<T>* root, T data) {
    if (data < root->data){
        return find(root->left_child, data);
    }
    else if (data > root->data){
        return find(root->right_child, data);
    }
    return root;
}

template <typename T>
void in_order_traversal(Node<T>* root) {
    if (root != nullptr) {
        in_order_traversal(root->left_child);
        std::cout << "Node: " << root->data << std::endl;
        in_order_traversal(root->right_child);
    }
}

template <typename T>
void pre_order_traversal(Node<T>* root) {
    if (root != nullptr) {
        std::cout << "Node: " << root->data << std::endl;
        pre_order_traversal(root->left_child);
        pre_order_traversal(root->right_child);
    }
}

template <typename T>
void post_order_traversal(Node<T>* root) {
    if (root != nullptr) {
        post_order_traversal(root->left_child);
        post_order_traversal(root->right_child);
        std::cout << "Node: " << root->data << std::endl;
    }
}

int main(int argc, char **argv) {
    Node<int>* root = new Node<int>(10);
    insert(root, 8);
    insert(root, 12);
    insert(root, 4);
    insert(root, 11);
    insert(root, 15);
    insert(root, 14);
    insert(root, 5);
    insert(root, 2);

    Node<int>* found_node = find(root, 14);
    found_node = find(root, 12);

    delete root;
    return 0;
}