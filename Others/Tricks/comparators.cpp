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

//Custom node
struct Node {
    int x, y;
    Node() {}
    Node(int a, int b): x(a), y(b){}
    //this will also work for sort() when you use this in vectors
    friend bool operator<(Node l, Node k) {
        return make_tuple(l.x, l.y) < make_tuple(k.x, k.y);  
    }
    //for priority queue, in non-decreasing order use '>' this sign in return, make_tuple() > make_tuple()
};

    


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    map<Node, int> mp;
    mp[{10, 20}] = 30;
    mp[{10, 10}] = 30;
    mp[{5, 10}] = 30;
    mp[{12, 5}] = 30;
    cout << endl << "map: \n";
    for (pair<Node, int> i: mp) {   //auto keyword also works
        cout << i.first.x << " : " << i.first.y << " " << i.second << endl;
    }

    //======================= VECTORS ================================
    cout << endl << "vector: \n";
    vector <Node> x = {{10, 20}, {10, 15}, {12, 5}, {3, 16}};
    sort(all(x));
    for (auto i: x)
        cout << i.x << ' ' << i.y << endl;
    cout << "lower_bound (10, 17): " << (lower_bound(all(x), Node(10, 17)) - x.begin()) << endl;

    
    //========================== SET ==============================
    cout << endl << "set: \n";
    set <Node> s = {{10, 20}, {10, 15}, {12, 5}, {3, 16}};
    for (auto i: s) {
        cout << i.x << ' ' << i.y << endl;
    }
    auto fnd = s.lower_bound(Node(20, 10));
    if(fnd != s.end())
        cout << "lower_bound (10, 17): (" << fnd->x << " " << fnd->y << ")"<< endl;


    //================ Pirority Queue ============================
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



/*
======================================
Above is a demo of "struct" when you want some custom node as key in set, multiset, map, priority_queue etc, then you need
to overload the operator< as friend function, then it works. It also works when you need to use struct in vectors and then
use sort(...) function.

NOTE: dont't use <= or >= for comparators instead, use : < or >.

========================================================================================
But suppose you want some "struct" and only want to use in vectors (not map, or self arrangement data structure) and then you can
just use:
struct Node {
    int a, b;
    Node() {}
    Node(int x, int y) : a(x), b(y){}
    bool operator<(Node o) {
        return make_tuple(a, b) < make_tuple(o.a, o.b);
    }
};

vector <Node> A = {{4, 2}, {1, 10}, {2, 4}};
sort(A.begin(), A.end());

================================== Another way ==================================
If you just want to use custom comparator:
//Custom Node
struct Node {
    int a, b;
    Node() {}
    Node(int x, int y) : a(x), b(y){}
};

//Custom comparator
struct cmp {
    bool operator()(Node x, Node y) {
        if (x.a != y.a) return x.a < y.a;
        return x.b < y.b;
    }
};


//pass the Node and custome comparator
set <Node, cmp> s;
s.insert({3, 2});
s.insert({2, 3});

*/

