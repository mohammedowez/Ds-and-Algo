class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int nobs, int &count){
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) return;   /* if out of range */
        if (grid[i][j] == -1) return;   /* if obstacle */
        if (grid[i][j] == 2) {          /* if reached end */
            if (nobs == 0) count++;     /* and all non obstacles are included in the path */
            return;
        }
        
        grid[i][j] = -1;   /* mark node visited so that it's explored exactly once in the current path */
        nobs = nobs - 1;   /* reduce the count of non-obstacle nodes visited so far */
        
        dfs(grid, i, j-1, nobs, count); // left
        dfs(grid, i, j+1, nobs, count); // right
        dfs(grid, i-1, j, nobs, count); // up
        dfs(grid, i+1, j, nobs, count); // down
        
        grid[i][j] = 0; /* make the node explorable again for other paths */
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int nobs = 0, i, j;
        // calculate start position and non-obstacles count
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    i = r;
                    j = c;
                }
                else if (grid[r][c] != -1) { // 0 or 2
                    nobs++;
                }
            }
        }
        int count = 0;
        dfs(grid, i, j, nobs, count);
        return count;
    }
};
