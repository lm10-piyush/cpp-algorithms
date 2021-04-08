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


//give the input in parameter
vector<int> brute(vector<int> &A) {
    //calculate ceil average
    int ans = 0;
    for (int i : A) ans += i;
    ans = ceil(1.0 * ans / sz(A));
    return vector<int>(ans);
}

//give the input in parameter
vector<int> efficient(vector<int> &A) {
    //to calculate the ceil average
    int ans = 0;
    for (int i : A) ans += i;
    ans = ceil((long double) ans / sz(A));
    return vector<int>(ans);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int times = 1; cin >> times;
    Random rd1(1, 10), rd2(1, 1000);  //rd1 => for n, rd2 => A[i]
    while (times--) {
        //random input....
        int n = rd1();
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = rd2();
        }

        //get solution........
        vector <int> sol1 = brute(A);    //correct solution
        vector <int> sol2 = efficient(A);  //efficient solution

        //test solution.........
        if (sz(sol1) != sz(sol2)) {
            //give warning 
            cout << "Wrong\n";
            cout << n << endl;
            for (int i: A) cout << i << ' ';
            
            return 0;
        }
        for (int i = 0; i < sz(sol1); ++i) {
            if (sol1[i] != sol2[i]) {
                //give warning
                cout << "Wrong\n";
                cout << n << endl;
                for (int i: A) cout << i << ' ';
                return 0;
            }
        }
        
    }

    cout << "all correct\n";

    return 0;
}

/*
If you want to work in strings then change the input and output format accordingly.
ex: we can use ascii codes.

*/