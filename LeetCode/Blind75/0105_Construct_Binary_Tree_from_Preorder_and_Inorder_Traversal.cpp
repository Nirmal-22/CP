// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int > idx;
    int preIndex=0;
    
    TreeNode* build(int left, int right, vector<int>& preorder){
        if(left>right) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = idx[rootVal];

        root->left = build(left, mid-1, preorder);
        root->right = build(mid+1, right, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx.clear();
        for(int i=0;i<inorder.size();i++)
            idx[inorder[i]] = i;
        
        preIndex =0;

        return build(0, inorder.size()-1, preorder);
    }
};
