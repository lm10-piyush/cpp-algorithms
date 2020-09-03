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
 
    int n, q; cin >> n >> q;
    vector <vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        for (int j = 0; j < n; ++j){
            A[i][j] = (s[j] == '*');
        }
    }
 
    vector <vector<int>> dp(n, vector<int>(n, 0));
    dp = A;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i) dp[i][j] += dp[i-1][j];
            if (j) dp[i][j] += dp[i][j-1];
            if (i and j) dp[i][j] -= dp[i-1][j-1];
        }
    }
 
 
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        int ans = dp[x2][y2];
        if (x1 > 0) ans -= dp[x1-1][y2];
        if (y1 > 0) ans -= dp[x2][y1-1];
        if (x1 > 0 and y1 > 0) ans += dp[x1-1][y1-1];
        cout << ans << endl;
    }
 
    return 0;
}

//https://cses.fi/problemset/task/1652

/*
https://codeforces.com/contest/846/problem/D  O(1) query
https://codeforces.com/contest/846/submission/91562490

*/