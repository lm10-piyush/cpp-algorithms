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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <ll> A(n), pref(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        pref[i] = A[i];
        if (i)
            pref[i] += pref[i - 1];
    }
    ll mn = pref[0], ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, pref[i] - mn);
        mn = min(mn, pref[i]);
    }

    cout << ans << endl;

    return 0;
}


/*
 * Idea is: subarray sum[i...j) : pref[i] - pref[j]
 * so, get the best answer for 'i', pref[j] should be minimum.
 * pref[i] - min(pref[i-1], pref[i-2]...pref[0])
 * This techniqe is useful when we have to find the max-subarray sum which contains elements atleast 'k'.

  https://codeforces.com/contest/1486/problem/D             (Example problem)
  https://codeforces.com/contest/1486/submission/113162907

 Resource:
 https://usaco.guide/silver/prefix-sums-2?lang=cpp

 * There are two other alternate approches also:
 1) Kadane.
 2) Divide and conquer.

*/