Input: matrix = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]
Output: [[7,4,1],
         [8,5,2],
         [9,6,3]]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        reverse(matrix.begin(), matrix.end());
    
        
        for(int i = 0; i<matrix.size();i++)
            for(int j=i; j<matrix.size();j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};
