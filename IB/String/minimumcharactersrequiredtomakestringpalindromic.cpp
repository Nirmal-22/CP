//not my code
int Solution::solve(string str) {

    // initial size of string str before updating it

    int init = str.size();


    // adding reverse of str to the end 

    string rev = str;

    reverse(rev.begin(),rev.end());

    str+= '#';

    str+=rev;

    

    // size of string str after updating it 

    int n = str.size(); 


    // store pi value for KMP ALGORITHM

    vector<int> pi(n+1,0);

    int j = 0;

    for(int i = 1 ;i<n;i++){

        j = pi[i-1];

        while(j>0 && str[i]!=str[j]){

            j = pi[j-1];

        }


        if(str[i]==str[j]){

            j++;

        }

        pi[i] = j;

    }

    // pi[n-1] is length of maximum palindromic substring that start at int i = 0 of str

    return init-pi[n-1];

}