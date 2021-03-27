#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int Min(int a, int b, int c){
        return min(a, min(b,c));
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i < m+1; i++)
            dp[i][0] = i;
        for(int j = 1; j < n+1; j++)
            dp[0][j] = j;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = Min(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1] + 1);
            }
        return dp[m][n];
    }
};