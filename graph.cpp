#include<iostream>
#include<vector>

class Node {
    public:
        int data;
        bool visited = false;
        std::vector<Node*> adj_list;
};

void depth_first_search(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << std::endl;
    root->visited = true;
    for (int i = 0; i < root->adj_list.size(); i++) {
        if (root->adj_list.at(i)->visited == false) {
        depth_first_search(root->adj_list.at(i));
        }
    }    
}

int main(int argc,char **argv) {
    std::vector<Node*> nodes;

    for (int i = 0; i < 7; i++) {
        Node* node = new Node;
        node->data = i;
        nodes.push_back(node);
    }

    nodes.at(0)->adj_list.push_back(nodes.at(1));
    nodes.at(0)->adj_list.push_back(nodes.at(4));
    nodes.at(0)->adj_list.push_back(nodes.at(5));

    nodes.at(1)->adj_list.push_back(nodes.at(3));
    nodes.at(1)->adj_list.push_back(nodes.at(4));
    
    nodes.at(2)->adj_list.push_back(nodes.at(1));
    
    nodes.at(3)->adj_list.push_back(nodes.at(2));
    nodes.at(3)->adj_list.push_back(nodes.at(4));

    depth_first_search(nodes.at(0));
    // next implement BFS and DFS

    return 0;
}