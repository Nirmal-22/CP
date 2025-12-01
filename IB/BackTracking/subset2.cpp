//not my code

void solve(vector <int>A, vector <int>i, vector <vector <int> > &v )
{
    if(A.size()==0)
    {
        if(find(v.begin(),v.end(),i)==v.end())
        {
            v.push_back(i);
        }        
        return;
    }

        vector<int> op1=i;
        vector<int> op2=i;

        op2.push_back(A[0]);
        A.erase(A.begin()+0);
        solve(A,op1,v);
        solve(A,op2,v);

}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    vector<vector<int> >v;
    vector<int> i;
    sort(A.begin(),A.end());
    solve(A,i,v);
    sort(v.begin(),v.end());
    return v;
}
