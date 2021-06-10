#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)

//Bottom UP, Efficient Solution O(N*K*log(N))
//https://codeforces.com/contest/321/problem/E

const int K = 803, N = 4003, INF = 1e9;
vector <vector <int>> dp(K, vector <int>(N, INF));
vector <vector <int>> pref(N, vector <int>(N));

auto cost = [&](int x1, int y1, int x2, int y2) {
    if (x2 < x1) return 0;
    int res = pref[x2][y2];
    if (y1) res -= pref[x2][y1 - 1];
    if (x1) res -= pref[x1 - 1][y2];
    if (x1 and y1) res += pref[x1 - 1][y1 - 1];
    return res / 2;
};

void DnC(int i, int j1, int j2, int k1, int k2) {
    if (j2 < j1) return;
    int mid = (j1 + j2) / 2;
    int best_k = k1;
    //finding the ans of segment to mid only [1...mid]
    //Via monotonicity, dp[i][mid] lies in k1..mid-1
    for (int k = k1; k <= min(mid - 1, k2); ++k) {
        int curr = dp[i - 1][k] + cost(k + 1, k + 1, mid, mid);
        if (curr < dp[i][mid]) {
            dp[i][mid] = curr;
            best_k = k;
        }
    }
    DnC(i, j1, mid - 1, k1, best_k);
    DnC(i, mid + 1, j2, best_k, k2);
}


//for fast input
inline int Read() {
    char ch = getchar();
    while (!((ch >= '0' && ch <= '9') || ch == '-')) ch = getchar();
    int x = 0, p = 1;
    if (ch == '-') p = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x * p;
}

int main() {

    int n = Read(), k = Read();
    vector <vector <int>> A(n, vector <int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) A[i][j] = Read();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pref[i][j] += A[i][j];
            if (i) pref[i][j] += pref[i - 1][j];
            if (j) pref[i][j] += pref[i][j - 1];
            if (i and j) pref[i][j] -= pref[i - 1][j - 1];
        }
    }
    //base case
    for (int i = 0; i < n; ++i) {
        dp[1][i] = cost(0, 0, i, i);
    }
    for (int i = 2; i <= k; ++i) {
        DnC(i, 0, n - 1, 0, n - 1);
    }

    cout << dp[k][n - 1];

    return 0;
}


/*
 ============= Top down ==================
 dp(i, j) => min cost so  that i-groups are already formed using 1..j-1 foxes and currently at jth fox
 dp(i, j) = min{dp(i+1, j+k) + cost(j, j+k-1)}, k = 1, 2, ...., k = elements in current group
https://codeforces.com/contest/321/submission/104148552

 ================== Bottom up =============================
 dp[i][j] = min cost so that current group  is ith and currently at jth fox
 dp[i][j] = min{dp[i-1][k] + cost(k+1, j)}, k <= i

 Lets optimize it using Divide and conqure DP, becuz it froms that type of recurrence + Monotonicity of K.
 Main key factor is montonicity of K, so to not try all possible, only try resonalbe K.

 First check for monotonicty: that means: opt(i, j) <= opt(i, j+1) <= opt(i, j+2)..
 opt(i, j) => minimum K required for dp[i][j] to get the optimize result.
 So, if we have prooved this: opt(i, j) <= opt(i, j+1) <= opt(i, j+2)..
 To proof it intutively we can see that as 'i' is fixed (number of groups) and 'j' increases then value of k
 will also increase, so k for opt(i, j+1) will lie after or equal to opt(i, j). This holds the monotonicity and
 we can apply the Divide and conqure to calcuate the states.

 How does it works?
 Suppose we are talking about some certain 'i'(which is fixed) and now update all the states related to the 'i'.
 Suppose I'm at currently some section [j1...j2] for which I have to calculate the DP dp[i][j1]... dp[i][j2].
 Instead of calculating the answer for all [j1...j2], we just find the answer for mid (mid = (j1 + j2) / 2) that is dp[i][mid],
 this dp[i][mid] will be optimial some value 'k', then we can say with monotocity that answer for segment: [j1...mid-1] will have the
 optimal <= k and similiary for segment [mid+1..j2], we know that answer will lie in >= k.

 It is fast because we don't need to go over all the states
 we just observe it from last state and just traverse only those states which are useful.


http://maratona.ic.unicamp.br/MaratonaVerao2017/documents/dp.pdf
https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html
https://codeforces.com/contest/321/problem/E

https://codeforces.com/contest/1077/problem/F2
https://codeforces.com/contest/1077/submission/104366757
using Queue: https://codeforces.com/contest/1077/submission/118180721

https://codeforces.com/contest/673/problem/E

*/
