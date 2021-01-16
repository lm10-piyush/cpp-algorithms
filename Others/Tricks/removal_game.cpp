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
 
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n; cin >> n;
    vector <ll> A(n);
    for (ll &i: A) cin >> i;
 
    vector <vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>>(n, {0,0}));
   
    for (int len = 1; len <= n; len++) {
        for (int i = 0, j = len-1; j < n; ++i, ++j) {
            if (i == j) dp[i][j] = {A[i], 0};
            else {
                ll best1 = A[i] + dp[i+1][j].second;
                ll best2 = A[j] + dp[i][j-1].second;
                if (best1 >= best2) {
                    ll player2 = dp[i+1][j].first;
                    dp[i][j] = {best1, player2};
                } else {
                    ll player2 = dp[i][j-1].first;
                    dp[i][j] = {best2, player2};
                }
            }
        }
    }
 
    cout << dp[0][n-1].first;
 
    return 0;
}
 
/*
player1 starts first,
current player tries to get the best

f(i, j).best => the best amount, player with the current turn will get from this range [i..j] will be f(i, j).turn1
 
best for turn1 f(i, j).better = {
                                    A[i],           if i == j
                                    max(A[i] + f(i+1, j).turn2, A[j] + f(i, j-1).turn2)
                                    f(i, j).turn2 will get 2nd best from the above section ie, f(i+1, j).turn1 or f(i, j-1).turn1
                               
                                }
 
https://cses.fi/problemset/task/1097
http://lightoj.com/volume_showproblem.php?problem=1031 (https://pastebin.com/xUEjseJ6)
 
*/