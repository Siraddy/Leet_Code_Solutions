#include <iostream>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}

};

int get_max_depth(TreeNode * root, int counter);
int maxDepth(TreeNode * root);

int get_max_depth(TreeNode * root, int counter) {
    if(root == nullptr) {
        return counter;
    } else {
        return std::max(get_max_depth(root -> right, counter + 1), get_max_depth(root -> left, counter + 1));
    }
}

int maxDepth(TreeNode * root) {
    return get_max_depth(root, 0);
}

int main() {

}
