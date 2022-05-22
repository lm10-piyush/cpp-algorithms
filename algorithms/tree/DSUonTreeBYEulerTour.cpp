#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

//DSU on trees using Euler tour
//We can also implement DSU on trees using Heavy light decomp also.

//Implementation of: https://codeforces.com/contest/600/problem/E

vector <vector <int>> tree;
vector <int> A, estart, eend; //euler start and end
vector <ll> tour, subSize, cnt, ans;
int tt = -1;
ll currMax, currSum; //max frequency, sum (shared variable and vector cnt is also shared)


void dfs1(int u, int p = -1) {
    estart[u] = ++tt;
    tour[estart[u]] = u;
    subSize[u] = 1;
    for (int v : tree[u]) {
        if (p == v) continue;
        dfs1(v, u);
        subSize[u] += subSize[v];
    }
    eend[u] = tt;  //here I didn't increase the counter
}

void dfs2(int u, int p = -1, bool keep = true) {
    int mx = 0, bigChild = 0;
    for (int v : tree[u]) {
        if (v == p) continue;
        if (subSize[v] > mx) {
            mx = subSize[v];
            bigChild = v;
        }
    }
    //first make calls on small childs
    for (int v : tree[u]) {
        if (v == p or v == bigChild) continue;
        dfs2(v, u, false);
    }
    //if bigChild exists, make dfs call on bigChild at last...
    if (bigChild) {
        dfs2(bigChild, u, true);
    }

    //Now, currMax, currSum contains the max frequency and sum of the subtree bigChild of 'u'.
    //becuz the effects of bigChild is not rolledback.

    cnt[A[u]]++;  //include current node
    if (cnt[A[u]] > currMax) {
        currMax = cnt[A[u]];
        currSum = A[u];
    } else if (cnt[A[u]] == currMax) {
        currSum += A[u];
    }

    for (int v : tree[u]) {
        if (v == p or v == bigChild) continue;
        //iterate on every node on subtree of 'u' except subtree of bigChild
        for (int i = estart[v]; i <= eend[v]; ++i) {
            cnt[A[tour[i]]]++;

            if (cnt[A[tour[i]]] > currMax) {
                currMax = cnt[A[tour[i]]];
                currSum = A[tour[i]];
            }
            else if (cnt[A[tour[i]]] == currMax) {
                currSum += A[tour[i]];
            }
        }
    }

    //now get the ans.. for current node
    ans[u] = currSum;

    //revert back the change if it is not the Bigchild
    if (!keep) {
        for (int i = estart[u]; i <= eend[u]; ++i) {
            cnt[A[tour[i]]]--;
        }
        currMax = 0, currSum = 0;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    tree.assign(n + 1, {});
    ans.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    A.resize(n + 1);
    estart.resize(n + 1);
    eend.resize(n + 1);
    tour.resize(n);
    subSize.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs1(1);
    dfs2(1);

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';

    return 0;
}


/*
 * Use dfs1() to calculate the subtree size, in and out time of every vertex. It is helpful to find the bigchild and other things.

 * Now apply dfs2(): We are building the answers from leaf to root. first find the bigChild (or you can precompute in dfs1() also.),
   then except on bigChild, apply dfs2() again on small child. When small childs are done, then apply on bigChild. Becuz we are using
   shared variable currMax, currSum. We are returning back to the parent of bigChild, then those variables already contains the frequency and sum for bigChild, so
   we don't need to compute for bigChild again. Now we are at 'u' which is the parent of bigChild, now iterate over each node in
   subtree of 'u' except the subtree of bigChild(becuz it is already computed). To iterate over the nodes we are using the euler
   time.
 * Now if the current node is not the bigChild then rollback the effects.
 * Main trick is to avoid recomputation on the bigChild and SAVE TIME.
 complexity = O(nlog(n)).

 * https://codeforces.com/blog/entry/44351  (blog)

  https://codeforces.com/contest/600/problem/E
  soln: above code. https://codeforces.com/contest/600/submission/94194076

 * https://www.hackerrank.com/contests/all-india-contest-by-mission-helix-a-6th-june/challenges/mex-the-tree/problem
  https://pastebin.com/GSQA6A0z  (MEX using Segment Tree)

  https://codeforces.com/contest/570/problem/D
  https://codeforces.com/contest/570/submission/94240034

  https://codeforces.com/contest/246/problem/E
  https://codeforces.com/contest/246/submission/94248509

 https://codeforces.com/contest/208/problem/E  (E. Blood Cousins, climbing, DSU on trees)
 https://codeforces.com/contest/208/submission/94405990

*/
