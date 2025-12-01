//not my code
string Solution::solve(string A) {

    int alpha[26] = {0}, f = 0; //f is first non repeating element

    string ans;

    for(int i = 0; i<A.length(); i++){

        alpha[A[i] - 'a']++;

        //loop to the first non repeating element

        while(alpha[A[f]-'a'] > 1 and f<i)

            f++;

        if(alpha[A[f]-'a'] == 1)

            ans += A[f];

        else

            ans += "#";

    }

    return ans;

}