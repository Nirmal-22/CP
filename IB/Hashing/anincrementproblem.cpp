//not my code
vector<int> Solution::solve(vector<int> &A) {

    unordered_map<int,int>mp;

    for(int i=0;i<A.size();i++)

    {

        if(mp.find(A[i])==mp.end())

        {

            mp[A[i]]=i; // if A[i] occurs first time

        }

        else 

        {

            int ind=mp[A[i]]; //store the index of last occurance

            mp[A[i]]=i;       // since A[i] is found again so its last value will be A[i]+1 

                               // so this value will be the A[i]

           int val=A[i]+1;// A[i]+1

           A[ind]=val;    // update the first occurance

           if(mp.find(val)==mp.end()) mp[val]=ind;  // if this A[i]+1 value not found

           else

           {

               if(mp[val]>ind) mp[val]=ind;  // if A[i]+1 found and this updated value occurs earlier in the array 

           }


        }

    }

    return A;

}

