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

template <class T>
class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        Node<T>* root;
        void insert(Node<T>* node);
        //bool search(T data);
        //void delete_node(T data); // idk how you specify a node
        // in order to do the above it seems like we need to traverse
        // the graph
        //Node<T>* in_order_traversal(T data);
        void in_order_traversal(Node node);
        //Node<T>* pre_order_traversal(T data);
        //Node<T>* post_order_traversal(T data);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root;
}

template <class T>
void BinarySearchTree<T>::insert(Node<T>* node) {
    if (root == nullptr) {
        root = node;
    }
    else {
        Node<T>* curr_node
    }
}

template <class T>
void BinarySearchTree<T>::in_order_traversal(Node<T> node) {
    if (node != nullptr) {
        in_order_traversal(node.left_node);
        std::cout << "Node value: "<< node.data << std::endl;
        in_order_traversal(node.right_node);
    }
}

int main(int argc, char **argv) {
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    return 0;
}