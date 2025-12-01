
//not my code

int Solution::solve(vector<vector<int> > &arr) {
    int  n=arr.size();
    int m=arr[0].size() ;
    for(int i=n-2;i>=0;i--){
     for(int j=0;j<m;j++){
        arr[i][j]=arr[i][j]+arr[i+1][j];    
        }
    }
    int maxi=-201 ;
    for(int i=n-1;i>=0;i--){
        int sum=0 ;
    for(int j=m-1;j>=0;j--){
          sum +=arr[i][j];
          maxi=max(maxi,sum);
        }
    }
    return maxi ;
   
}
