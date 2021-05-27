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

//Monotonic stack => maintaining the elements in sorted fashion
//Calculating the Nearest greater element at the left using Monotonic stack

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int n; cin >> n;
  vector <int> A(n);
  for (int &i : A) cin >> i;

  stack <int> s;   //Elements are stored in increasing order.
  vector <int> NGL(n);
  for (int i = 0; i < n; ++i) {
    while (!s.empty() and A[s.top()] < A[i])
      s.pop();
    NGL[i] = (s.empty() ? 0 : A[s.top()]);
    s.push(i);
  }
  for (int i : ans)
    cout << i << ' ';

  return 0;
}


/*
 * This is one of the most famous use of stack, which helps to make the complexity O(n), otherwise you can use Sparsetable with Binary serach
   which has complexity: O(n.log(n)).
 * I call these problem as Envelop problems because here we greedily removes and add the elements and if we join event indicies using a line
   the it looks like an Envelop or Convex hull.
 * It helps to skip the elements greedily and efficiently.
 * You can solve other similar problems like Nearest Minimum left, Nearest Maximum Right and Nearest minimum left.
 * Same concept is used in many problems like Largest Area under histogram, Largest area rectangle of 1's in a binary matrix etc, DP problems etc.

   Problems:
   https://leetcode.com/problems/largest-rectangle-in-histogram/
   Solution is in the same directory.

   https://cses.fi/problemset/task/1645

   https://codeforces.com/contest/1313/problem/C2
   https://codeforces.com/contest/1313/submission/112107300

   https://www.codechef.com/LTIME94A/problems/LUNCHTIM

   https://leetcode.com/problems/maximal-rectangle/
   https://pastebin.com/MPdHrXqY

   https://www.hackerrank.com/contests/cisco-icode-round-2/challenges/sherlock-and-subarray/problem
   https://pastebin.com/PjPD64HH
*/