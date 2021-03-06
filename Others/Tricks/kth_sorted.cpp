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
 * Here the problem invovles: given some rules to create some array/string, find the kth sorted array or lexicographically minimum string.
 * Mostly we have to use here Greedy approach, with combinatorics: Like given an integer N, represent it in sum of powers of two such that each power of 2 must be distinct.

 * ex: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ebe5e
 * https://atcoder.jp/contests/abc202/tasks/abc202_d
 * https://www.hackerearth.com/problem/algorithm/binary-inversions-cf645357/

*/