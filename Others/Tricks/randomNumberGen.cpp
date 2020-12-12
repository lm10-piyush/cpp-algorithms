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

struct Random {
    mt19937 rng;
    uniform_int_distribution<int> num;
    Random(int a, int b) {
        auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        rng = mt19937(seed);
        num = uniform_int_distribution <int> (a, b);
    }
    int operator()() {
        return num(rng);
    }
};

struct Randoom {
    mt19937 rng;
    Randoom() {
        auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        rng = mt19937(seed);
    }
    int operator ()(int a, int b) {
        return uniform_int_distribution<int> (a, b)(rng);
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    //*******************************
    int t; cin >> t;
    int a, b; cin >> a >> b;
    Random rdx(a, b);  //To generate the number between [a, b] (int) otherwise change into long long to bigger range
    while (t--) {
        cout << rdx() << endl;
    }

    //******************* another ways, it think it is simple
    Randoom rox;
    t = 10;
    while (t--) {
        cout << rox(1, 10) << endl;
    }


    return 0;
}
