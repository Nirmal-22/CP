//not my code

int Solution::compareVersion(string A, string B) {
    // Trace it A = "128.000345.00235" & B = "128.000345.236"

    int i = 0, j = 0;

    int m = A.size(), n = B.size(); // m = 16 & n = 14

    while(i<m && j<n){

        int k = i, l = j;           // k = 0, l = 0

        while(i<m && A[i]!='.')i++; // find first stop at '.'

        while(j<n && B[j]!='.')j++; // find first stop at '.'

        

        string str1 = A.substr(k, i-k); // str1 = "128" -> "000345" -> "00235"

        string str2 = B.substr(l, j-l); // str2 = "128" -> "000345" -> "236"

        

        int p = 0, q = 0;

        

        while(p < str1.size() && str1[p] == '0')p++;// skip trailing 0s in str1: "128"->"128", "00345"->"345, "00235"->"235""

        while(q < str2.size() && str2[q] == '0')q++;// skip trailing 0s in str2: "128"->"128", "00345"->"345", "236"->"236"

        

        if(str1.size()-p > str2.size()-q) return 1;//"128"=="128"(goto else), "345"=="345"(goto else), "235"<"236"(goto else)

        else if(str1.size()-p < str2.size()-q)  return -1;//"128"=="128"(come out), "345"=="345"(come out), "235"<"236"(return -1)

        

        while(p < str1.size() && q < str2.size() && str1[p] == str2[q]){//(p=0,q=0), (p=2,q=2), -1 already returned

            p++;

            q++;

        }

        // (p=3,q=3), (p=5,q=5), -1 already returned

        if(p < str1.size() && q < str2.size()){//(p=3,q=3)(goto else), (p=5,q=5)(goto else), -1 already returned

            return (str1[p] > str2[q]) ? 1 : -1;

        }else if(p < str1.size() && q > str2.size())//(p=3,q=3)(goto else), (p=5,q=5)(goto else), -1 already returned

            return 1;

        else if(p > str1.size() && q < str2.size())//(p=3,q=3)(goto else), (p=5,q=5)(goto else), -1 already returned

            return -1;

       

        

        i++;// i=4, 11, 16

        j++;// j=4, 11, 14

    }

    

    if(i >= m && j < n) {

        while(j < n && B[j] == '0')j++;

        if(j >= n) return 0;

        else return -1;        

    }else if(i < m && j >= n) {

        while(i < m && A[i] == '0')i++;

        if(i >= m) return 0;

        else return 1;   

    }

    else return 0;
}
