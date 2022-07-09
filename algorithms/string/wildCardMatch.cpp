// https://leetcode.com/problems/wildcard-matching/submissions/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector <vector <bool>> dp(n + 1, vector <bool> (m + 1, false));
        dp[0][0] = true;
        //handling zero length cases separately
        for (int i = 0; i < m; ++i) {
            if (p[i] == '*') {
                dp[0][i + 1] = true;
            }
            else break;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                }
            }
        }
        return dp[n][m];
    }
};

/*

dp[i][j] = is it possible to match s[1..i], p[1..j]
dp[i][j] = {
    if (p[j] != any_wild_card(* or ?))
        dp[i][j] = dp[i-1][j-1] && s[i] == p[j]
    else if (p[j] == '?')
        dp[i][j] = dp[i-1][j-1];
    else {
        dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
         => dp[i][j-1] => treat * as empty
         => dp[i-1][j] => treat * as ith character but don't stop including in *
         => dp[i-1][j-1] => treat * as ith character, not stop doing this
    }

}

*/