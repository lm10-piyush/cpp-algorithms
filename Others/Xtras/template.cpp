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



	return 0;
}


/*
 * When a problem requires alot of case work then go for generalized solution.
 * For generalization: smart brute-force, converting into different problem (like tree/graphs), efficient simulation etc.
 * Stay calm, give your best.
 * Read problem carefully, sometimes you read it wrong and thought that problem is difficult.
 * Whenever you start practising the only goal should be to improve yourself by:
    learning new ideas, building focus, giving 100% etc.
*/