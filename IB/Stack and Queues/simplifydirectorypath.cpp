//not my code

string Solution::simplifyPath(string a) {
    stack<string> s;
   
    long long n = a.length();
   
    for(long long i=0; i<n; i++)
    {
       
        if(a[i] != '/')
        {
            string temp = "";
            long long j = i;
            while(a[j]!='/' && j<n)
            {
                j++;
            }
            temp = a.substr(i, j-i);
            if(temp == ".." && !s.empty())
            {
                s.pop();
            }
            else if(temp != "." && temp!="..")
            {
                s.push(temp);
            }
            i = j-1;
        }
       
    }
    string ans = "";
    string temp = "";
    if(s.empty())
    {
        return "/";
    }
   
    while(!s.empty())
    {
        // ans= "/" + s.top() + ans; TLE
       
        temp = "/";
        temp.append(s.top());
        temp.append(ans);
        ans = temp;
       
        s.pop();
    }
    return ans;