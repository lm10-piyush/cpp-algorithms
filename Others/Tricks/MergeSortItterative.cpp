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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vector <int> A(n);
    for (int &i: A) {
      cin >> i;
    }
    vector <int> B = A;
    for (int i = 1; i < n; i *= 2) {
      for (int j = 0; j < n-1; j += 2*i) {
        int mid = min(j+i-1, n-1);
        int right = min(j + 2*i-1, n-1);
        // watch(i, j, mid, right);   //uncomment it to watch segments
        vector <int> L(A.begin()+j, A.begin()+mid+1), R(A.begin()+mid+1, A.begin()+right+1);
        merge(all(L), all(R), A.begin()+j);
      }
    }
    for (int i: A) cout << i << ' ';

    return 0;
}

/*
 * When you uncomment that line, you might see the tree structure of recursive and iterative one is not same but the
 idea/concept is same. Iterative one is complete tree(left ward oriented) but recursive one not need to be complete tree.

*/
