#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int)v.size() 
#define all(v) v.begin(), v.end()
void dbg_out() { cerr << "\b\b]\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << H << ", "; dbg_out(T...);}
#define watch(...) cerr << "[" << #__VA_ARGS__ << "]: [", dbg_out(__VA_ARGS__)


/****************************** CODE IS HERE ***********************************/

bool used[1002][1002];

//perfix sums on Matrix with updates
struct BIT {
    vector <vector<int>> bit;
    int n;
    BIT() {
        n = 1001;
        bit.assign(n+2, vector<int> (n+2, 0));
    }
    void upd(int x, int y) { 
        for (++x; x <= n; x += x&-x) {  
            for (int j = y+1; j <= n; j += j&-j) { 
                bit[x][j] += 1;
            }
        }
    }
    int qry(int x, int y) {
        int res = 0;
        for (++x; x > 0; x -= x&-x) {
            for (int j = y+1; j > 0; j -= j&-j) {
                res += bit[x][j];
            }
        }
        return res;
    }

    int qry(int x1, int y1, int x2, int y2) {
        int ans = qry(x2, y2) - qry(x2, y1-1) - qry(x1-1, y2) + qry(x1-1, y1-1);
        return ans;
    }
};


void solve() {
    int q; cin >> q;
    BIT ft;
    memset(used, false, sizeof used); //this is just for requriment of the 1st problem lightoj
    while (q--) {
        int type; cin >> type;
        if (type == 0) {
            int x, y; cin >> x >> y;
            if (!used[x][y]) {
                ft.upd(x, y);
                used[x][y] = true;
            }
        }
        else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            int ans = ft.qry(x1, y1, x2, y2);
            printf("%d\n", ans);
            // cout << ans << endl;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case %d:\n", i);
        solve();
    }


    return 0;
}

/*
http://lightoj.com/volume_showproblem.php?problem=1266

https://www.spoj.com/problems/MATSUM/
soln: https://pastebin.com/dPL5E84z

https://cses.fi/problemset/task/1739

*/