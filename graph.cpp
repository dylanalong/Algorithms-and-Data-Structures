#include<iostream>
#include<vector>

class Node {
    public:
        char data;
        std::vector<char> adj_list;
};

int main(int argc,char **argv) {
    std::vector<Node*> nodes;

    for (int i = 0; i < 7; i++) {
        Node* node = new Node;
        node->data = 'a' + i;
        nodes.push_back(node);
    }

    // A
    nodes.at(0)->adj_list.push_back('b');
    nodes.at(0)->adj_list.push_back('d');

    // B
    nodes.at(1)->adj_list.push_back('a');
    nodes.at(1)->adj_list.push_back('e');

    // C
    nodes.at(2)->adj_list.push_back('f');
    
    // D
    nodes.at(3)->adj_list.push_back('a');
    nodes.at(3)->adj_list.push_back('e');

    // E
    nodes.at(4)->adj_list.push_back('b');
    nodes.at(4)->adj_list.push_back('d');
    nodes.at(4)->adj_list.push_back('f');

    // F
    nodes.at(5)->adj_list.push_back('c');
    nodes.at(5)->adj_list.push_back('e');

    // next implement BFS and DFS

    return 0;
}