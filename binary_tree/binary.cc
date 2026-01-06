#include "../util/tree_node.hpp"
#include <iostream>

int main() {
    std::vector<int> input_vals = {1, 2, 3, -1, 6, 4, 5}; // -1 表示 null
    auto root = BinaryTree::createFromVector(input_vals);
    std::cout << "createFromVector from {1, 2, 3, -1, 6, 4, 5}. " << std::endl;

    // 为每个遍历创建独立的向量
    std::vector<int> pre_vals, in_vals, post_vals;

    // 执行迭代遍历
    auto pre_iter = BinaryTree::preorderIter(root);
    auto in_iter = BinaryTree::inorderIter(root);
    auto post_iter = BinaryTree::postorderIter(root);

    std::cout << "迭代前序遍历结果为: ";
    for (size_t i = 0; i < pre_iter.size(); ++i) {
        std::cout << pre_iter[i] << (i == pre_iter.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;

    std::cout << "迭代中序遍历结果为: ";
    for (size_t i = 0; i < in_iter.size(); ++i) {
        std::cout << in_iter[i] << (i == in_iter.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;

    std::cout << "迭代后序遍历结果为: ";
    for (size_t i = 0; i < post_iter.size(); ++i) {
        std::cout << post_iter[i] << (i == post_iter.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;


    // 执行递归遍历，使用独立向量
    BinaryTree::preorderRec(root, pre_vals);
    std::cout << "递归前序遍历结果为: ";
    for (size_t i = 0; i < pre_vals.size(); ++i) {
        std::cout << pre_vals[i] << (i == pre_vals.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;

    BinaryTree::inorderRec(root, in_vals);
    std::cout << "递归中序遍历结果为: ";
    for (size_t i = 0; i < in_vals.size(); ++i) {
        std::cout << in_vals[i] << (i == in_vals.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;

    BinaryTree::postorderRec(root, post_vals);
    std::cout << "递归后序遍历结果为: ";
    for (size_t i = 0; i < post_vals.size(); ++i) {
        std::cout << post_vals[i] << (i == post_vals.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;

    // 对于 levelorder，也使用独立向量
    std::vector<int> level_vals;
    // 注意：这里对哪个树进行层序遍历？根据您的原始代码，是 create_root。我们保留这个逻辑。
    // 但请注意 createTree() 是交互式的，结果依赖于您的输入。
    // 如果您想对 root 树进行层序遍历，应调用 BinaryTree::levelorder(root, level_vals);
    // auto create_root = BinaryTree::createTree(); // 如果需要交互式创建
    // BinaryTree::levelorder(create_root, level_vals);
    
    // 为了演示和与原始代码保持一致（假设 create_root 是一个已知结构或您已提供输入），
    // 我们对 root 树进行层序遍历。
    BinaryTree::levelorder(root, level_vals); 
    std::cout << "层序遍历 (对 root 树): ";
    for (size_t i = 0; i < level_vals.size(); ++i) {
        std::cout << level_vals[i] << (i == level_vals.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;

    BinaryTree::deleteTree(root);
    // 如果您创建了 create_root，请记得删除它
    // BinaryTree::deleteTree(create_root);

    return 0;
}