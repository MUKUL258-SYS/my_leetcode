class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int localMaxCount = 0;

        // 3D Prefix Sum array: pref[threshold_value][row][col]
        // Size is 201 because values go up to 200. Matrix dims + 1 to handle 1-based indexing for prefix math.
        vector<vector<vector<int>>> pref(201, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));

        // Step 1: Pre-calculate the 3D Prefix Sums
        for(int v = 1; v <= 200; v++) {
            for(int r = 0; r < n; r++) {
                for(int c = 0; c < m; c++) {
                    int isStrictlyGreater = (matrix[r][c] > v) ? 1 : 0;
                    
                    // 2D Inclusion-Exclusion build formula
                    pref[v][r + 1][c + 1] = pref[v][r][c + 1] + 
                                            pref[v][r + 1][c] - 
                                            pref[v][r][c] + 
                                            isStrictlyGreater;
                }
            }
        }
        
        // Step 2: Query each cell in O(1) time
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                int x = matrix[r][c];
                if(x == 0) continue; 

                // Define the rectangular boundaries of the blast radius
                int topRow = max(0, r - x);
                int bottomRow = min(n - 1, r + x);
                int leftCol = max(0, c - x);
                int rightCol = min(m - 1, c + x);

                // O(1) mathematical lookup for how many numbers > x are inside this exact rectangle
                int greaterCount = pref[x][bottomRow + 1][rightCol + 1] - 
                                   pref[x][topRow][rightCol + 1] - 
                                   pref[x][bottomRow + 1][leftCol] + 
                                   pref[x][topRow][leftCol];
                
                // Step 3: Corner Cleanup (Ignore the 4 absolute extreme corners)
                int exactTop = r - x;
                int exactBottom = r + x;
                int exactLeft = c - x;
                int exactRight = c + x;

                // If a corner is inside the grid AND was strictly greater than x, remove it from our count
                if(exactTop >= 0 && exactLeft >= 0 && matrix[exactTop][exactLeft] > x) greaterCount--;
                if(exactTop >= 0 && exactRight < m && matrix[exactTop][exactRight] > x) greaterCount--;
                if(exactBottom < n && exactLeft >= 0 && matrix[exactBottom][exactLeft] > x) greaterCount--;
                if(exactBottom < n && exactRight < m && matrix[exactBottom][exactRight] > x) greaterCount--;
                
                // If nothing greater exists in the considered area, it's a local maximum
                if(greaterCount == 0) {
                    localMaxCount++;
                }
            }
        }
        
        return localMaxCount;
    }
};