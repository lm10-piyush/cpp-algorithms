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

struct Graph {
    struct Edge {
        int v, w;
    };
    int v, e;
    vector <vector<Edge>> Edges;  //adj list
    Graph(int _v, int _e) {
        v = _v;
        e = _e;
        Edges.resize(_v+1);
    }
    

    void addEdge(int u, int v, int w) {
        Edges[u].push_back({v, w}); //directed edge
    }

};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    Graph g(n, m);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    for (int i = 0; i <= n; ++i){
       for (int j = 0; j < g.Edges[i].size(); ++j){
            cout << i << ": ";
            cout << g.Edges[i][j].v << " " << g.Edges[i][j].w << ", ";
       }
        cout << endl;
    }


    return 0;
}
