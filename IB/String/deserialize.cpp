vector<string> Solution::deserialize(string A) 
{
    vector<string> ans;
    
    int x=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='~')
        {
            int j;
            for(j=i-1;j>0;j--)
            {
                if(A[j]>='a' && A[j]<='z') break;
            }
            
            ans.push_back(A.substr(x,(j-x+1)));
            x=i+1;
        }
    }
    
    return ans;
}
