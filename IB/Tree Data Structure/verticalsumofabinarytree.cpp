/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::verticalSum(TreeNode* root) {
    vector<int> table;

	if(!root) return table;

	int hd=0;
	// root->hd=hd;
	map<TreeNode*,int> mp;

	mp[root]=  0;

	map<int,vector<int>> ans;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty())
	{
		TreeNode* nd= q.front();
		q.pop();

		// hd=nd->hd;
		hd = mp[nd];

		ans[hd].push_back(nd->val);

		if(nd->left)
		{
// 			nd->left->hd=hd-1;
            mp[nd->left]=hd-1;
			q.push(nd->left);
		}

		if(nd->right)
		{
// 			nd->right->hd=hd+1;
            mp[nd->right]=hd+1;
			q.push(nd->right);
		}
	}

	for(auto it=ans.begin();it!=ans.end();it++)
	{
		// table.push_back(it->second);
		auto sum=0;
		for(auto x=0;x<it->second.size();x++)
			sum+= it->second[x];

		table.push_back(sum);
	}

	return table;
}
