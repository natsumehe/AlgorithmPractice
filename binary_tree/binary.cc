#include "../util/tree_node.hpp"
#include <iostream>

int main() {
    std::vector<int> vals = {1, 2, 3, -1, 6, 4, 5}; // -1 表示 null
    auto root = BinaryTree::createFromVector(vals);

    auto create_root = BinaryTree::createTree();
    std::cout <<"自己创建："<<create_root -> val;
   
    auto pre = BinaryTree::preorderIter(root);
    std::cout << "Preorder: ";
    for (int x : pre) std::cout << x << " ";
    std::cout << "\n";

    BinaryTree::deleteTree(root);
    return 0;
}