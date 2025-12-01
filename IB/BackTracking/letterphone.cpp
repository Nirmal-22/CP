vector<string> Solution::letterCombinations(string A) 
{
    vector<vector<char>> v={{'0'},{'1'},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

	string s="";
	vector<string> ans;
	function<void(int)> dfs=[&](int x)
	{
		
		if(x==A.size()) 
		{
		    ans.push_back(s);
    		return;
		}

		for(int i=0;i<v[A[x]-'0'].size();i++)
		{
			s=s+ v[A[x]-'0'][i];
			dfs(x+1);
			s.pop_back();
		}
	};
	dfs(0);

	return ans;
}
