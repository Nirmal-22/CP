//was playing valorant.... braindead....cant do a problem
//not my code
string Solution::intToRoman(int A) {
    string ans="";
    int arr[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string alph[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    for(int i=0;i<13;i++)
    {
        while(A>=arr[i])
        {
            ans+=alph[i];
            A=A-arr[i];
        }        
    }
    return ans;
}