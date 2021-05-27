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

//another way to write the code.
//NOTE: array<int, N> is memory efficient than vector<int> (N).
void solve() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n);
    for (auto &i : A)
        cin >> i;

    vector <vector <array <ll, 2>>> dp(n, vector <array <ll, 2>>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = A[i];
        dp[i][i][1] = 0;
    }

    for (int x = 2; x <= n; ++x) {
        for (int l = 0, r = x - 1; r < n; ++l, ++r) {
            dp[l][r][0] = max(A[l] + dp[l + 1][r][1], A[r] + dp[l][r - 1][1]);
            dp[l][r][1] = min(dp[l + 1][r][0], dp[l][r - 1][0]);
        }
    }

    cout << dp[0][n - 1][0];

}

//Top-down
void solve() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n);
    for (auto &i : A)
        cin >> i;

    vector <vector <array <ll, 2>>> dp(n, vector <array <ll, 2>>(n, { -1, -1}));
    function <ll(int, int, int)> go = [&](int l, int r, int flag) {
        if (l > r)
            return 0LL;
        if (dp[l][r][flag] != -1)
            return dp[l][r][flag];
        ll ans;
        if (flag) { //to get the second best
            ans = min(go(l + 1, r, 0), go(l, r - 1, 0));
        }
        else { //to get the best
            ll best1 = A[l] + go(l + 1, r, 1);
            ll best2 = A[r] + go(l, r - 1, 1);
            ans = max(best2, best1);
            //since it is top-down we don't have to call explicitly for the second best, it done implicitly in above best1, best2.
        }
        return dp[l][r][flag] = ans;
    };

    cout << go(0, n - 1, 0);
}

//using pairs
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n);
    for (ll &i : A) cin >> i;

    vector <vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, {0, 0}));

    for (int len = 1; len <= n; len++) {
        for (int i = 0, j = len - 1; j < n; ++i, ++j) {
            if (i == j) dp[i][j] = {A[i], 0};
            else {
                ll best1 = A[i] + dp[i + 1][j].second;
                ll best2 = A[j] + dp[i][j - 1].second;
                if (best1 >= best2) {
                    ll player2 = dp[i + 1][j].first;
                    dp[i][j] = {best1, player2};
                } else {
                    ll player2 = dp[i][j - 1].first;
                    dp[i][j] = {best2, player2};
                }
            }
        }
    }

    cout << dp[0][n - 1].first;

    return 0;
}

/*
player1 starts first,
current player tries to get the best, next player choses the best from the rest part.
I don't need to keep track of which player is currently playing. Just assume 1st player is current player and choses the best and
next player is 2nd player choses best from remaining part.

f(i, j).best => the best amount, player with the current turn will get from this range [i..j] will be f(i, j).turn1

best for turn1 f(i, j).better = {
                                    A[i],           if i == j
                                    max(A[i] + f(i+1, j).turn2, A[j] + f(i, j-1).turn2)
                                    f(i, j).turn2 will get 2nd best from the above section ie, f(i+1, j).turn1 or f(i, j-1).turn1

                                }

https://cses.fi/problemset/task/1097
http://lightoj.com/volume_showproblem.php?problem=1031 (https://pastebin.com/xUEjseJ6)

===============================================================

/*
 * min-max game
 * f(l, r, 0) => best from A[l..r] for the current player
 * f(l, r, 1) => second best score can get from A[l..r] for the current player
 * Current player always choses to get the best score, the next player choses the best from the rest part.
 * f(l, r, 0) => max(A[l] + f(l+1, r, 1), A[r] + f(l, r-1, 1))
   f(l, r, 1) => min(A[l] + f(l+1, r, 0), f(l, r-1, 0))

*/


* /