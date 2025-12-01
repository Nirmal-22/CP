string Solution::solve(string A) 
{
    string s=A;
    int n=A.length();
    
    {
        for(int i=0;i<(n/2);i++)
        s[n-1-i]=s[i];
 
        if(s>A)
        return s;
    }
    
    
    {
        s=A;
        int flag=1;
        for(int i=0;i<(n/2);i++)
        {
            if(s[i]!='9')
            {
                flag=0;
                break;
            }
        }   

        string s2;
        if(flag==1) 
        {
            s2+='1';
            for(int i=1;i<n;i++) s2+='0';
            s2+='1';
            
            return s2;
        }
        
    }
    
    {
        s=A;
        
        if(n%2==0)
        { 
            int x=(n/2-1);
            
            while(s[x]=='9')
            {
                s[x]='0';
                x--;
            }
            s[x]++;
        }
        else
        {   
            int x=n/2;
            
            while(s[x]=='9')
            {
                s[x]='0'; // characters in singles quotes...
                x--;
            }
            s[x]++;
        }
        
        for(int i=0;i<(n/2);i++)
            s[n-1-i]=s[i];
        
        return s;
    }
}