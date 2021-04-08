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
        (ans += go(pos + 1, (rem + i) % d, newtight)) %= mod; //sum of digits
    }
    return dp[pos][rem][tight] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s >> d;
    for (char i : s) {
        num.push_back(i - '0');
    }
    memset(dp, -1, sizeof dp);

    ll ans = go(0, 0, 1) % mod;
    ans = (ans - 1 + mod) % mod;          //becuz 000...0 is not allowed
    cout << ans;

    return 0;
}

/*
https://codeforces.com/blog/entry/77096  (Bottom up dp)


just trying all possibilities, using brute force then cache the calls.
https://atcoder.jp/contests/dp/tasks/dp_s

https://www.codechef.com/problems/KANYASAI
soln: https://www.codechef.com/viewsolution/29212253

https://www.hackerearth.com/problem/algorithm/weird-number-e7dc0051/
https://pastebin.com/jAiqXvns

https://codeforces.com/contest/1036/problem/C
https://codeforces.com/contest/1036/submission/95498710  (Top-down solution)
https://codeforces.com/contest/1036/submission/95501389  (Bottom-up solution)
https://codeforces.com/contest/1036/submission/95527462  (bottom up memory optimized)

https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
https://pastebin.com/GYaPuSm9

https://codeforces.com/gym/100886/problem/G
https://pastebin.com/PZTU54iM

https://codeforces.com/contest/628/problem/D
https://codeforces.com/contest/628/submission/107072882

*/
