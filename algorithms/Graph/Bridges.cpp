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

//NOTE: here we are talking in sense of DFS tree: parent, child, tree-edge, back-edge etc.
//DFS tree: https://codeforces.com/blog/entry/68138

vector <vector<int>> g;
vector <int> lo, tin;
vector <bool> used;
vector <pair<int,int>> bridge;
int id = 0;

void dfs(int u, int p) {
    used[u] = true;
    lo[u] = tin[u] = id++;
    for (int v: g[u]) {
        if (v == p) continue;
        if (used[v]) lo[u] = min(lo[u], tin[v]); //visiting already visited node(via back edge) then update the low link value.
        else {
            dfs(v, u);
            lo[u] = min(lo[u], lo[v]);   //coming back from the recursion then update the low link value.
            if (tin[u] < lo[v]) 
                bridge.push_back({min(u, v), max(u, v)}); //this min, max is done only to maintain order
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    id = 0;
    bridge.clear();
    g.assign(n+1, {});
    lo.resize(n+1);
    tin.resize(n+1);
    used.assign(n+1, false);

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //loop used, graph can be disconnected
    for (int i = 1; i <= n; ++i) {
        if (!used[i])
            dfs(i, -1);
    }
    sort(all(bridge));  //optional acording to need of problem
    cout << "Bridges:\n";
    for (auto i: bridge)
        cout << i.first << ' ' << i.second << endl;

    return 0;
}

/*
 * Concept of Bridges is in undirected graph. 
 * Here is the main concept of back edges. Tarjan Algorithm is used to find the bridges.
 * In most of the problems we need to sort the bridges array and u < v order maitained.
 * Observation: Each component apart by bridges have same low link value.  
 * lo[u] => minimum time reachable by the descendants of 'u' in the DFS spanning tree.
 * We conver the graph into the tree such that each node in the tree will be whole component of original graph whose
   lo[] value is same.
 * Observation: low value of the component is same (not necessarily, to condense the graph use DSU).

 * In line-32, we have done tin[u] < lo[v] instead of lo[u] < lo[v], because lo[u] < lo[v] is incorrect. Because lo[u] < lo[v] will
   count those edges also which are not bridges, if the back-edge from u is way behind the lo[v] then it will count that edge as bridge which is wrong.

 * Note: Be careful, sometimes it looks like this could be done using Bridges conceptt, then think carefully, because there could be concept of articulation point.

 https://onlinejudge.org/external/7/796.pdf
 https://pastebin.com/urXutKaZ
    
 https://www.spoj.com/problems/EC_P/  (Just above code)

 https://www.codechef.com/COCA2020/problems/PRTWHY
 solution: https://www.codechef.com/viewsolution/35308948

 https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-hackerearth-3/description/
 https://pastebin.com/wqmpJtrW    (Graphs gets restored after each operation)


 https://www.hackerearth.com/problem/algorithm/weird-number-e7dc0051/  (convert the graph into the tree using lo value.)
 https://pastebin.com/99c5t4eg

 https://codeforces.com/contest/1000/problem/E          (Bridges, condensation of graph, diamter of tree, DSU)
 https://codeforces.com/contest/1000/submission/104892785 
 https://codeforces.com/contest/1000/submission/104890623     (Don't do these types of things to condense the graph such as lo[] value, insted use: DSU)
*/