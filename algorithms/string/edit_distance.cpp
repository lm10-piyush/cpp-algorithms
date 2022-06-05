#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

void solve() {
    string a, b; cin >> a >> b;
    int n = sz(a);
    int m = sz(b);
    vector <vector <int>> dp(m + 1, vector <int> (n + 1, 0));
    for (int i = 0; i <= n; ++i)
        dp[0][i] = i;
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (b[i - 1] == a[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;

        }
    }

    cout << dp[m][n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--)
        solve();


    return 0;
}

/*
We have 3 choices if current letters don't match : replace, insert, delete.

START from the last position to first, b => [N....1], same as a => [M...1],
i = m, j = n; (remember we are moving back to front)
if they matched then, just decrement both pointers.
if they don't matched then for: replace, replace the a[j] with the b[i], +1 operation required then just decrement both pointers
                                insert, insert the character at a[j+1], +1 operation required then just drecment only ith pointer
                                      becuz b[i] is matched with a[j+1].
                                delete, delete the a[j], +1 operation required, then just decrement the jth pointer, becuz element is deleted.
                                pick the best one => min(replace, insert, delete) + 1
Recurrence : if s[i] == s[j] then dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1; //replace, insert, delete

=============================================================================================================
To use bottom up: dp[i][j] => minimum number of edits required in a[1...i] and b[1...j] (we are at currently (i, j), so, current state is included)
to calculate: dp[i][j], we have exclude the current state and move to previous state, because as we define above dp[i][j] is included current state.
And to get the best ans for dp[i][j], we have to find the best combination of previous move(state) and current state.
But we don't know, which previous state was optimal with current state, so we try every possiblity by assuming if we have done this operation:
if a[i] == b[j], it should not effect then dp[i][j] = dp[i-1][j-1]
else {
    //Assume, if we've done insertion operation currently (current state (i, j)) at jth, then previous state would be (by undoing / exclude the curren operation): dp[i-1][j]
    //Asume, if we've done replace operation currently at jth, then previous state would be: dp[i-1][j-1]
    //assume, if we've done deletion at current at jth, then previous state would be: dp[i][j-1]
    cost = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1
}
========================================================================================================


https://www.spoj.com/problems/EPALIN/
https://cses.fi/problemset/task/1639

https://atcoder.jp/contests/abc185/tasks/abc185_e
Sequence Matching, like LCS or Edit distance, top-down sol: https://atcoder.jp/contests/abc185/submissions/18771904, bottom-up : https://atcoder.jp/contests/abc185/submissions/18771958

https://leetcode.com/problems/edit-distance/
*/