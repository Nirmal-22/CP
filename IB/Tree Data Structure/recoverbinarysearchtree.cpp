/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* root) {
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    while (root != nullptr) {
        if (root->left != nullptr) {
            TreeNode* predecessor = root->left;
            while (predecessor->right != nullptr && predecessor->right != root) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = root;
                root = root->left;
            } else {
                predecessor->right = nullptr;

                if (prev != nullptr && prev->val > root->val) {
                    if (first == nullptr) {
                        first = prev;
                    }
                    second = root;
                }

                prev = root;
                root = root->right;
            }
        } else {
            if (prev != nullptr && prev->val > root->val) {
                if (first == nullptr) {
                    first = prev;
                }
                second = root;
            }

            prev = root;
            root = root->right;
        }
    }

    if (first != nullptr && second != nullptr) {
        std::swap(first->val, second->val);
    }

    vector<int> v;
    if (first != nullptr) v.push_back(first->val);
    if (second != nullptr) v.push_back(second->val);
    return v;
}
