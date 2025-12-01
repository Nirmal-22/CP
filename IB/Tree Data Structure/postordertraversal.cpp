//not my code
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> st1, st2;
    TreeNode* node = A;
    vector<int> v;

    // Push the root node to the first stack
    st1.push(node);

    // Loop while the first stack is not empty
    while(!st1.empty())
    {
        // Pop a node from the first stack
        node = st1.top();
        st1.pop();

        // Push the popped node to the second stack
        st2.push(node);

        // Push the left and right children of the popped node to the first stack
        if(node->left != NULL)
        {
            st1.push(node->left);
        }
        if(node->right != NULL)
        {
            st1.push(node->right);
        }
    }

    // Pop nodes from the second stack and add their values to the vector
    while(!st2.empty())
    {
        node = st2.top();
        st2.pop();
        v.push_back(node->val);
    }

    return v;
}
