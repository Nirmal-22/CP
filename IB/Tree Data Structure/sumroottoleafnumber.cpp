/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void sumRootToLeaf(TreeNode* root, int currentSum,int& sum) 
{
    if (root == nullptr)
        return;

    currentSum = (currentSum * 10 + root->val) % 1003;

    if (root->left == nullptr && root->right == nullptr)
    {
        sum = (sum+currentSum)%1003;
    }

    sumRootToLeaf(root->left, currentSum,sum);
    sumRootToLeaf(root->right, currentSum,sum);
}

int Solution::sumNumbers(TreeNode* A) 
{
    int sum = 0;
    sumRootToLeaf(A, 0,sum);
    return sum;
}
