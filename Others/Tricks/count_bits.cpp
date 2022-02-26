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
#define LM10_Piyush
#ifdef LM10_Piyush
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)
#else
#define watch(...)
#endif

/*
 * Ques: Given a number 'n', find the total number of set bits at ith position in range [0, a] (inclusive).
 * ex: n = 10
 * In numbers => [0, 10]
 * number of bits at position:
   0th => 3
   1th => 4
   2th => 5
   3th => 5
   from 4th to 30th => all will be 0.
*/

vector <int> bitCount(int a) {
	vector <int> cnts(31);
	ll p = 2;
	for (int i = 0; i < 30; ++i) {
		cnts[i] = (a / p) * (p / 2);
		ll rem = a % p + 1;
		cnts[i] += max(0LL, rem - (p / 2));
		p *= 2;
	}
	return cnts;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	vector <int> cnts = bitCount(n);
	watch(cnts);

	return 0;
}


/*
 Ex: https://pastebin.com/sRER8yfB                    (Xor sum of [a, b] with [c, d])
*/