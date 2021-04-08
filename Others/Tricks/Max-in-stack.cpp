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

//Find the max in the stack
//To do this we store a pair of (value, max)
//We can also do this using monotonic stack


template <typename T>
struct Stack {
	stack <pair<T, T>> s;
	void push(T x) {
		T mx = (s.empty() ? x : max(s.top().second, x));
		s.push({x, mx});
	}
	T top() {
		if (s.empty())
			return -1;
		return s.top().first;
	}
	T qry() {
		if (s.empty())
			return -1;
		return s.top().second;
	}
	void pop() {
		s.pop();
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int n; cin >> n;
	Stack <int> s;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			s.push(x);
		}
		else if (t == 2)
			cout << s.top() << endl;
		else if (t == 3)
			s.pop();
		else cout << s.qry() << endl;
	}

	return 0;
}


/*

*/