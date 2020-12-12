#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

void solve() {
    string a, b; cin >> a >> b;
    int n = sz(a);
    int m = sz(b);
    vector <vector <int>> dp(m+1, vector <int> (n+1, 0));
    for (int i = 0; i <= n; ++i)
        dp[0][i] = i;
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (b[i-1] == a[j-1])
                dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            
        }
    }

    cout << dp[m][n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--)
        solve();


    return 0;
}

/*
We have 3 choices if current letters don't match : replace, insert, delete.

start from the last position to first, b => [N....1], same as a => [M...1],
i = m, j = n; (remember we are moving back to front)
if they matched then, just decrement both pointers.
if they don't matched then for: replace, replace the a[j] with the b[i], +1 operation required then just decrement both pointers 
                                insert, insert the character at a[j+1], +1 operation required then just drecment only ith pointer
                                      becuz b[i] is matched with a[j+1].
                                delete, delete the a[j], +1 operation required, then just decrement the jth pointer, becuz element is deleted. 
                                pick the best one => min(replace, insert, delete) + 1
Recurrence : if s[i] == s[j] then dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1; //replace, insert, delete

https://www.spoj.com/problems/EPALIN/
https://cses.fi/problemset/task/1639

*/