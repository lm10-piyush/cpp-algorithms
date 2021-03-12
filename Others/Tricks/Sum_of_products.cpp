#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

//https://www.spoj.com/problems/SUMPRO/

const int mod = 1e9 + 7;

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modMul(ll a, ll b) {
    if (a >= mod) a %= mod;
    if (b >= mod) b %= mod;
    return (a * b) % mod;
}

void solve() {
    ll n; cin >> n;
    ll ans = 0, srt;
    for (ll i = 1; i*i <= n; ++i) {
        ans += modMul((n / i), i);
        ans %= mod;
        srt = i;
    }
    ll inv = power(2, mod-2);
    auto sum = [&](ll x) {  //sum of first x numbers
        return modMul(x, modMul(x+1, inv));
    };
    //IF, floor(n / x) = a, how many x's statisfies the equation
    //these are: x belongs to [n/(a+1) + 1, n / a], on these numbers floor(n / x) = a
    for (ll k = 1; k*k <= n; ++k) { //iterating on i => (n / x)
        int r = n / k;
        int l = n / (k+1) + 1;
        l = max(l*1LL, srt + 1);
        ans += modMul(k, sum(r) - sum(l-1)); //k = (n / i), so, we are finding, what 'i's will have same multiplicant as 'k' 
        ans %= mod;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;  cin >> t;
    while (t--) solve();

    return 0;
}


/*
 * goal : summation(i * floor(n / i))
   as we know the relation between i, n/i: when 'i' <= sqrt(n) then floor(n/i) >= sqrt(n) {mostly, edge case is sqrt(n)}
   when floor(n/i) <= sqrt(n) then i >= sqrt(n).

   After this observation, we note that, one of the thing will be <= sqrt(n).
   So, I've split the solution in two parts: 1) i <= sqrt(n), and 2) floor(n / i) <= sqrt(n)
   1) this is easy to calculate
   2) for each floor(n / i) which values 'i' will give me this floor(n/i), ex: n = 37, i={10, 11, 12}, on these n / i is same.
      To calculate it we have seen them they lies in range: [n / (i+1) + 1, n / i] or (n/(i+1), n/i]. 
      Note just take care of special case: root, because this could be counted twice, so 'l' must be greater than sqrt(n)

 https://codeforces.com/contest/616/problem/E
 https://codeforces.com/contest/616/submission/107675039
*/





