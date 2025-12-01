vector<string> Solution::specialStrings(vector<string> &A) {
    string s;
	vector<string> ans;


	function<void(int)> dfs = [&](int i)
	{
		if(i==A.size())
		{
			ans.push_back(s);
			return;
		}

		for(int j=0;j<A[i].length();j++)
		{
			s.push_back(A[i][j]);
			i++;
			dfs(i);
			i--;
			s.pop_back();
		}
	};
	dfs(0);

	sort(ans.begin(),ans.end());

	return ans;
}
