//my code 
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    stack<TreeNode*>st;
    TreeNode* node = A;
    vector<int>v;
    while(true)
    {
       if(node != NULL)
       {
           st.push(node);
           node = node ->left;
       }
       else
       {
           if(st.empty())
           {
               break;
           }
           node = st.top();
           st.pop();
           v.push_back(node->val);
           node = node -> right;
       }
    }
    return v;
}
