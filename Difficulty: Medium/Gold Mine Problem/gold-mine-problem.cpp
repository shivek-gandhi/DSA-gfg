class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();        // number of rows
    int m = mat[0].size();     // number of columns

    // Create dp table of same size as mat
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Traverse from last column to first
    for (int col = m - 1; col >= 0; col--) {
        for (int row = 0; row < n; row++) {
            // If we are not in the last column, calculate possible moves
            int right = (col == m - 1) ? 0 : dp[row][col + 1];
            int right_up = (row == 0 || col == m - 1) ? 0 : dp[row - 1][col + 1];
            int right_down = (row == n - 1 || col == m - 1) ? 0 : dp[row + 1][col + 1];

            dp[row][col] = mat[row][col] + max({right, right_up, right_down});
        }
    }

    // Find the max value in the first column
    int maxGold = 0;
    for (int i = 0; i < n; i++) {
        maxGold = max(maxGold, dp[i][0]);
    }

    return maxGold;
    }
};