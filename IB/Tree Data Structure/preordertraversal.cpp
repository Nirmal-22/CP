/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::preorderTraversal(TreeNode* A) 
{
    stack<TreeNode*>st;
    TreeNode* node = A;
    vector<int>v;
    // st.push(A);
    while(true)
    {
       if(node != NULL)
       {
           st.push(node);
           v.push_back(node->val);
           node = node->left;
       }
       else
       {
           if(st.empty())
           {
               break;
           }
           node = st.top();
           st.pop();
        //    v.push_back(node->val);
           node = node -> right;
       }
    }
    return v;
}