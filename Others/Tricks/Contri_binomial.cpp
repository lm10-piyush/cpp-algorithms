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

#define double long double

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <double> A(n);
    for (double &i: A) cin >> i;

    //dp[i] => after 'i' tosses, dp[j] represents the probablity to getting 'j' heads, 0 <= j <= i
    //rest of code is implementation... 
    vector <double> dp(n+1, 0);
    dp[0] = 1;
    for (int coins = 0; coins < n; ++coins) {
        for (int i = coins+1; i >= 0; --i) {
            dp[i] = (i ? dp[i-1]*A[coins] : 0) + dp[i]*(1 - A[coins]);
        }
    }

    double ans = 0;
    for (int heads = 0; heads <= n; ++heads) {
        int tails = n - heads;
        if (heads > tails) ans += dp[heads];
    }

    cout << fixed << setprecision(10);
    cout << ans;



    return 0;
}

//https://atcoder.jp/contests/dp/tasks/dp_i
//the main part of this problem is good implementation of nCr