#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Edge case: If start or end cell is blocked, no path exists
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        
        // Edge case: 1x1 matrix with an open cell
        if (n == 1) {
            return 1;
        }
        
        // 8-directional movement offsets (row, col)
        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        // Queue stores pair of coordinates: {row, col}
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        // Mark the starting cell as visited by overriding it to 1
        grid[0][0] = 1;
        
        int pathLength = 1;
        
        while (!q.empty()) {
            int currentLevelSize = q.size();
            
            // Process all nodes at the current distance level
            for (int i = 0; i < currentLevelSize; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                // If we reached the bottom-right corner, return path length
                if (r == n - 1 && c == n - 1) {
                    return pathLength;
                }
                
                // Explore all 8 adjacent neighbors
                for (auto& dir : directions) {
                    int newR = r + dir[0];
                    int newY = c + dir[1];
                    
                    // Check boundaries and check if the neighbor cell is open (0)
                    if (newR >= 0 && newR < n && newY >= 0 && newY < n && grid[newR][newY] == 0) {
                        // Mark as visited instantly to prevent duplicate queue insertion
                        grid[newR][newY] = 1; 
                        q.push({newR, newY});
                    }
                }
            }
            // Increment the step count after evaluating the current level
            pathLength++;
        }
        
        return -1;
    }
};
