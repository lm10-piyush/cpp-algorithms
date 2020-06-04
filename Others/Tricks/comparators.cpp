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

struct Node {
    int x, y;
    Node() {}
    Node(int a, int b): x(a), y(b){}
    friend bool operator<(Node l, Node k) {
        return make_tuple(l.x, l.y) < make_tuple(k.x, k.y);
    }
};

    


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    map<Node, int> mp;
    mp[{10, 20}] = 30;
    mp[{10, 10}] = 30;
    mp[{5, 10}] = 30;
    mp[{12, 5}] = 30;
    cout << endl << "map: \n";
    for (pair<Node, int> i i: mp) {   //auto keyword also works
        cout << i.first.x << " : " << i.first.y << " " << i.second << endl;
    }


    cout << endl << "vector: \n";
    vector <Node> x = {{10, 20}, {10, 15}, {12, 5}, {3, 16}};
    sort(all(x));
    for (auto i: x)
        cout << i.x << ' ' << i.y << endl;
    cout << "lower_bound (10, 17): " << (lower_bound(all(x), Node(10, 17)) - x.begin()) << endl;

    

    cout << endl << "set: \n";
    set <Node> s = {{10, 20}, {10, 15}, {12, 5}, {3, 16}};
    for (auto i: s) {
        cout << i.x << ' ' << i.y << endl;
    }
    auto fnd = s.lower_bound(Node(20, 10));
    if(fnd != s.end())
        cout << "lower_bound (10, 17): (" << fnd->x << " " << fnd->y << ")"<< endl;



    cout << endl << "priority_queue: \n";
    priority_queue <Node> pq;
    pq.push({10, 20});
    pq.push({10, 15});
    pq.push({12, 5});
    pq.push({3, 16});
    while (!pq.empty()) {
        Node x = pq.top();
        cout << x.x << ' ' << x.y << endl;
        pq.pop();
    }

    return 0;
}
