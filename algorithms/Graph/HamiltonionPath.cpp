#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <bool>> graph(n, vector <bool> (n, false));
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }

    //Check for Hamiltonion walk
    //dp[i][mask] => Is there any hamiltonion walk using the vertices in 'MASK' such that we end up at node 'i'
    vector <vector <bool>> dp(n, vector <bool> (1 << n, false));

    //single node will be considered as correct
    for (int i = 0; i < n; ++i)
        dp[i][1 << i] = true;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                for (int j = 0; j < n; ++j) {
                    if ((mask >> j & 1) and j != i and graph[j][i])
                        dp[i][mask] = dp[i][mask] || dp[j][mask ^ (1 << i)];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dp[i][(1 << n) - 1]) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}


/*
 * Hamiltonion walk of nodes Graph(n, m): traversing each node exactly once.
 * #paths = #walk / 2

 * This is the concept of Dp on subset of graphs.
 * https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/
   https://codeforces.com/blog/entry/337

 * https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/practice-problems/algorithm/micro-and-coins/
 * Same as above code.

 * https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/practice-problems/algorithm/fredos-crush-2/
 * https://pastebin.com/vbgNHY3z

 * https://codeforces.com/contest/11/problem/D          (number of simple cyles, Important, Cool DP state)
 * https://codeforces.com/contest/11/submission/111456686

 * https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/practice-problems/algorithm/fredo-and-his-birthday-gift-4/
 * https://pastebin.com/Mu0qeNXs
 * https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/practice-problems/algorithm/micro-and-permutations/
 * https://pastebin.com/3zEBhkJv

 * https://www.codechef.com/problems/TOOLS       (Same as travelling salesman)
 * https://www.codechef.com/viewsolution/44335592
*/
