#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

const int N = 1e5 + 3;
vector <int> tree[N];

vector<int> centroid(int n) {
    vector <int> centroids;
    //dfs function to find centroid.
    function<int(int, int)> dfs = [&](int u, int p) {
        int s = 1;
        bool is_centroid = true;
        for (int v: tree[u]) {
            if (v == p) continue;
            int sub = dfs(v, u);
            s += sub;
            if (sub > n/2) is_centroid = false;
        }
        if (n - s > n / 2) is_centroid = false;
        if (is_centroid) centroids.push_back(u);
        return s;
    };
    dfs(1, -1);
    return centroids;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector <int> centroids = centroid(n);
    for (int i: centroids) cout << i << ' ';


    return 0;
}

/*
Centroid always divides the tree such that each component's size won't be greater than n/2 where n is number of nodes in a tree.

Note: There will always a centroid and atmost two centroids are possible which are adjacent to each other.

https://codeforces.com/problemset/problem/1406/C
https://codeforces.com/contest/1406/submission/101152845

*/
