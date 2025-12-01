//not my code

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(A);
    while(q.size()){
        int n = q.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            TreeNode* t = q.front();
            q.pop();
            if(t->left) { q.push(t->left); v.push_back({t->left->val, t->val});}
            if(t->right) { q.push(t->right); v.push_back({t->right->val, t->val});}
        }
        int p=-1;
        for(auto i : v){
            if(i.first==B) {p=i.second; break;}
        }
        if(p!=-1)
        {for(auto i : v){
            if(i.second!=p)
            ans.push_back(i.first);
        }
        return ans;
        }
    }
    return ans;
}