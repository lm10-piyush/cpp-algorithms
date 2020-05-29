#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define arr_watch(arr, n) for(int i=0;i<n;++i) cout<<arr[i]<<" \n"[i==n-1]
using namespace std;

//IN-OUT dp for height of each node when that node is root.
//similarly in-out dp is apply at many occasions like score at each node when that node is root.

const int maxn = 1e5;
vector<int> graph[maxn + 5];
int in[maxn + 5], out[maxn + 5];
int ans[maxn + 5];

void dfs1(int u, int p){
    in[u] = 0;
    for (int v: graph[u]){
        if(v == p) continue;
        dfs1(v, u);
        in[u] = max(in[u], 1+in[v]);
    }
}

void dfs2(int u, int p){
    int mx1(-1), mx2(-1);
    for (int v: graph[u]){
        if(v == p) continue;
        if(in[v] >= mx1) mx2 = mx1, mx1 = in[v];
        else if(in[v] > mx2) mx2 = in[v];
    }

    for (int v: graph[u]){
        if(v == p) continue;
        int use = mx1;
        if(use == in[v])
            use = mx2;
        out[v] = max(2+use, 1 + out[u]);
        dfs2(v, u);
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    
    // freopen("D:/TestFiles/input.txt","r",stdin);
    
    #endif
    /*********************** CODE IS HERE *****************************************/


    int n; cin >> n;
    for (int i = 0, x,y; i < n-1; ++i){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //assumed rooted at node-1
    dfs1(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; ++i){
        ans[i] = max(in[i], out[i]);
        cout << ans[i] << ' ';
    }

    return 0;
}