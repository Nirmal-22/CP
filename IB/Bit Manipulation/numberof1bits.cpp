/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int numSetBits(unsigned int A) 
{
    int c=0;
    while(A>0)
    {
        if(A & 1)
        c++;
        
        A=A>>1;
    }
    
    return c;
}
