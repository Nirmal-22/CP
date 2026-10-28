// 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
        int m= mt.size(), n=mt[0].size();
        bool row0=false, col0=false;

        for(int i=0;i<m;i++)
            if(mt[i][0]==0) col0=true;
        for(int j=0;j<n;j++)
            if(mt[0][j]==0) row0=true;

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                if(mt[i][j]==0)
                    mt[i][0] = mt[0][j] = 0;
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                if(mt[i][0]==0 || mt[0][j]==0)
                    mt[i][j]=0;
        
        if(col0) for(int i=0;i<m;i++) mt[i][0]=0;
        if(row0) for(int j=0;j<n;j++) mt[0][j]=0;
    }
};
