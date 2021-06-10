#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
using namespace std;

//IN-OUT dp for height of each node when that node is root.
//similarly in-out dp is apply at many occasions like score at each node when that node is root.
//We can also say it RE-rooting..(kind of inclusion-exclusion)
//problem: find the diameter of the given tree when ith node is root node.

const int maxn = 1e5;
vector<int> graph[maxn + 5];
int in[maxn + 5], out[maxn + 5];
int ans[maxn + 5];

void dfs1(int u, int p) {
    in[u] = 0;
    for (int v : graph[u]) {
        if (v == p) continue;
        dfs1(v, u);
        in[u] = max(in[u], 1 + in[v]); //height of the node in the subtree of u
    }
}

void dfs2(int u, int p) {
    int mx1(-1), mx2(-1);
    for (int v : graph[u]) {
        if (v == p) continue;
        if (in[v] >= mx1) mx2 = mx1, mx1 = in[v];
        else if (in[v] > mx2) mx2 = in[v];
    }
    //being at 'u' set the value of 'out' of the vertx 'v' which is child of u
    for (int v : graph[u]) {
        if (v == p) continue;
        int use = mx1;
        if (use == in[v])
            use = mx2;
        out[v] = max(2 + use, 1 + out[u]);
        dfs2(v, u);
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE

    // freopen("D:/TestFiles/input.txt","r",stdin);

#endif
    /*********************** CODE IS HERE *****************************************/


    int n; cin >> n;
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //assumed rooted at node-1
    dfs1(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; ++i) {
        ans[i] = max(in[i], out[i]);
        cout << ans[i] << ' '; //height of the ith node
    }

    return 0;
}

/*
 * How much is the contribution of the particular edge in the tree as number of paths passing throught it. It will be
 (number of nodes in one end) * (number of nodes in the another end)

*/

// https://cses.fi/problemset/task/1132

// https://codeforces.com/problemset/problem/337/D
//https://codeforces.com/contest/337/submission/73440952


//https://codeforces.com/contest/120/problem/F
//https://codeforces.com/contest/120/submission/76465143

/*
https://www.spoj.com/problems/EAGLE1/  (tree dp, in-out, as above code but here edges are weighted)
https://pastebin.com/Q6ApmdCn

https://codeforces.com/contest/1324/problem/F            (maximum white subtree)
https://codeforces.com/contest/1324/submission/105045087

https://www.spoj.com/problems/PT07Z/
solution: is ans = max(ans, in[i] + out[i])

https://atcoder.jp/contests/dp/tasks/dp_p
Tree dp, basic counting, https://atcoder.jp/contests/dp/submissions/19922830

https://codeforces.com/contest/1401/problem/D  (dp contribution techniq)
https://codeforces.com/contest/1401/submission/90882209

https://codeforces.com/problemset/gymProblem/102694/B
https://pastebin.com/53kX4tqG

https://codeforces.com/contest/161/problem/D  (with inclusion-exlusion principal)
https://codeforces.com/contest/161/submission/102405695

https://codeforces.com/contest/1187/problem/E  (dhansu problem)
https://codeforces.com/contest/1187/submission/95686227

https://cses.fi/problemset/task/1133
https://pastebin.com/ZdfhdNFh

https://cses.fi/problemset/task/1130   (tree edges, cool dp problem, tree matching (maximum matching))
https://pastebin.com/V85rFfYz

https://codeforces.com/contest/1223/problem/E    (Paint the Tree, extension of above problem, Exchange arguments, dp)

https://codeforces.com/contest/1529/problem/C    (tree dp, convex function, with some greediness, https://codeforces.com/contest/1529/submission/117534553)
*/