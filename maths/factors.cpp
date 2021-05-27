#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

vector <ll> pFactor(ll n) {
    vector <ll> v;
    for (ll i = 2; i * i <= n; ++i) {
        while (n  % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        v.push_back(n);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    vector <ll> f = pFactor(n);
    for (auto i : f)
        cout << i << ' ';

    return 0;
}


/*
 * Factors of 'n' exists in pairs, and the middle number is root(n).
 that means: n = 12,
 then factors: (2, 6), (1, 12), (3, 4) in pairs
 Thats why number of factors of a perfect square number is odd, and for non-perfect square number is even.


*/
//https://www.spoj.com/problems/FACT0/      (factoring using seive)
//https://pastebin.com/gwEK1ZfT

//https://codeforces.com/contest/1025/problem/B
//https://codeforces.com/contest/1025/submission/90256368

//https://codeforces.com/contest/1285/problem/C
//https://codeforces.com/contest/1285/submission/69926022


//https://www.spoj.com/problems/COMDIV/
//https://pastebin.com/LEw7WvwW

//https://www.spoj.com/problems/DIVSUM/
//https://pastebin.com/7AQ4yEhX