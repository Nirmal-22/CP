//not my code
int Solution::solve(int A) 
{
    int i=0,x=0,c=0;
        int num=abs(A);
        while(x<num|| (x-num)%2!=0){
        c++;
        i++;
        x+=i;
        }
    return c;
}
