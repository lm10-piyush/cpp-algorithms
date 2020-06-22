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
int d;
vector <int> num;
const int mod = 1e9 + 7;
ll dp[10004][103][2];


ll go(int pos, int rem, int tight) {
    if (pos == sz(num)) {
        return !rem;
    }
    if (dp[pos][rem][tight] != -1) return dp[pos][rem][tight];

    int limit = (tight ? num[pos] : 9);
    ll ans = 0;
    for (int i = 0; i <= limit; ++i) {
        int newtight = tight;
        if (i < limit) newtight = 0;
        (ans += go(pos+1, (rem + i) % d, newtight)) %= mod;
    }
    return dp[pos][rem][tight] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s >> d;
    for (char i: s) {
        num.push_back(i - '0');
    }
    memset(dp, -1, sizeof dp);

    ll ans = go(0, 0, 1) % mod;
    ans = (ans - 1 + mod) % mod;          //becuz 000...0 is not allowed
    cout << ans;

    return 0;
}

/*
just trying all possibilities, using brute force then cache the calls.
https://atcoder.jp/contests/dp/submissions/14598857

https://www.codechef.com/problems/KANYASAI
soln: https://www.codechef.com/viewsolution/29212253
*/
