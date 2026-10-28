// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mt) {
        int m = mt.size(), n= mt[0].size();

        vector<int> result;

        int top=0, bottom=m-1, left=0, right=n-1;

        while(top<=bottom && left<=right){

            for(int col=left; col<=right; col++)
                result.push_back(mt[top][col]);
            top++;

            for(int row=top; row<=bottom; row++)
                result.push_back(mt[row][right]);
            right--;

            if(top<=bottom)
            {
                for(int col=right; col>=left; col--)
                result.push_back(mt[bottom][col]);
            bottom--;
            }

            if(left<=right)
            {
                for(int row=bottom; row>=top; row--)
                result.push_back(mt[row][left]);
            left++;
            }

        }
        return result;
    }
};
